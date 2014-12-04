#include "connection.h"
#include "logger.h"
#include <thread>

#include <sstream>
#include <functional>
#include <thread>

using namespace std;
using namespace std::placeholders;

void connection::dump_event(irc_session_t *session, const char *event, const char *origin, const char **params, unsigned count) {
    string info;

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
    logger::log(logstring.str());

    irc_ctx_t *ctx = static_cast<irc_ctx_t *>(irc_get_ctx(session));
    emit(ctx->conn->text_received(QString(logstring.str().c_str())));
}

void connection::event_numeric(irc_session_t *session, unsigned event, const char *origin, const char **params, unsigned count) {
    char buf[24];
    sprintf (buf, "%d", event);

    dump_event (session, buf, origin, params, count);
}

void connection::event_connect(irc_session_t *session, const char *event, const char *origin, const char **params, unsigned count) {
    irc_ctx_t *ctx = static_cast<irc_ctx_t *>(irc_get_ctx(session));
    dump_event(session, event, origin, params, count);

    irc_cmd_join(session, ctx->channel, 0);
}


connection::connection() {
    callbacks.event_connect = event_connect;
    callbacks.event_numeric = event_numeric;

    session = irc_create_session(&callbacks);
}

connection::~connection() {
    if (irc_is_connected(session)) {
        irc_cmd_quit(session, "Kebap mit Zwiebeln");
    }
    disconnect();
}

bool connection::connect(user &user, server &server) {
    if(!session) return false;
    ctx.nick = user.get_nick().c_str();
    ctx.conn = this;
    irc_set_ctx(session, &ctx);
    string logstring("establishing connection to " + server.get_address());
    emit(text_received(QString(logstring.c_str())));
    if(irc_connect(session, server.get_address().c_str(), server.get_port(), 0,
                user.get_nick().c_str(), user.get_nick2().c_str(),
                user.get_fullname().c_str())){
        logger::log("could not establish connection.");
        return false;
    };

    std::thread(&connection::run, this, session).detach();

    return true;
}

void connection::run(irc_session_t *session) {
    logger::log("starting irc loop in new thread");
    if (irc_run(session)) {
        // TODO: Display connection not possible window
        string logstring("connection could not be established: " + string(irc_strerror(irc_errno(session))));
        logger::log(logstring);
        emit(text_received(QString(logstring.c_str())));
        return;
    }
    // TODO: Display disconnected from server window?
    logger::log("user disconnected from server");
}

void connection::disconnect() {
    irc_disconnect(session);
    irc_destroy_session(session);
}

