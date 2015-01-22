#include "connection.h"
#include "logger.h"

#include <sstream>


using namespace std;

void connection::dump_event(irc_session_t *session, const char *event, const char *origin, const char **params, unsigned count) {
    string info;
    if(origin) info.append(origin).append("| ");
    for (unsigned i = 0; i < count; i++) {
        if (i) {
            info.append("|");
        }
        info.append(params[i]);
    }
    stringstream logstring;
    logstring << "Event \"" << event
              << "\", origin: \"" << (origin ? origin : "NULL")
              << "\", params: " << int(count) << "[" << info << "]" << endl;
    logger<DEBUG>::log(logstring.str());

    irc_ctx_t *ctx = static_cast<irc_ctx_t *>(irc_get_ctx(session));
    emit(ctx->conn->text_received(QString(info.c_str())));
}

void connection::event_numeric(irc_session_t *session, unsigned event, const char *origin, const char **params, unsigned count) {
    char buf[24];
    sprintf (buf, "%d", event);

    dump_event (session, buf, origin, params, count);
}

void connection::event_connect(irc_session_t *session, const char *event, const char *origin, const char **params, unsigned count) {
    irc_ctx_t *ctx = static_cast<irc_ctx_t *>(irc_get_ctx(session));
    dump_event(session, event, origin, params, count);
}

void connection::event_join(irc_session_t *session, const char *event, const char *origin, const char **params, unsigned count) {
    irc_ctx_t *ctx = static_cast<irc_ctx_t *>(irc_get_ctx(session));
    dump_event(session, event, origin, params, count);
    emit(ctx->conn->channel_joined(QString(params[0])));
}

void connection::event_channel(irc_session_t *session, const char *event, const char *origin, const char **params, unsigned count){
    dump_event(session, event, origin, params, count);
    irc_ctx_t *ctx = static_cast<irc_ctx_t *>(irc_get_ctx(session));
}


connection::connection() {
    memset (&callbacks, 0, sizeof(callbacks));
    callbacks.event_connect = event_connect;
    callbacks.event_join = event_join;
    callbacks.event_channel = event_channel;

    callbacks.event_numeric = event_numeric;

    session = irc_create_session(&callbacks);
}

connection::~connection() {
    disconnect();
    irc_disconnect(session);
    irc_destroy_session(session);
}

bool connection::connect(const user &user, const server &server) {
    if(!session) return false;
    ctx.nick = user.get_nick().c_str();
    ctx.conn = this;
    irc_set_ctx(session, &ctx);
    string logstring("establishing connection to " + server.get_address());
    emit(text_received(QString(logstring.c_str())));
    if(irc_connect(session, server.get_address().c_str(), server.get_port(), 0,
                user.get_nick().c_str(), user.get_nick2().c_str(),
                user.get_fullname().c_str())){
        logger<ERROR>::log("could not establish connection.");
        return false;
    };

    looper = std::thread([this]{run(session);});
    return true;
}

void connection::run(irc_session_t *session) {
    logger<DEBUG>::log("starting irc loop in new thread");
    if (irc_run(session)) {
        // TODO: Display connection not possible window
        string logstring("disconnected: " + string(irc_strerror(irc_errno(session))));
        logger<DEBUG>::log(logstring);
        emit(text_received(QString(logstring.c_str())));
    }
}

void connection::disconnect() {
    if (irc_is_connected(session)) {
        irc_cmd_quit(session, "Kebap mit Zwiebeln");
        looper.join();
    }
}

void connection::execute_command(command *cmd) const{
    cmd->execute(session);
}

