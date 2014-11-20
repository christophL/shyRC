#include "connection.h"
#include "logger.h"


#include <sstream>

using namespace std;

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
    irc_callbacks_t callbacks;
    memset (&callbacks, 0, sizeof(callbacks));

    callbacks.event_connect = event_connect;
    callbacks.event_numeric = event_numeric;

    session = irc_create_session(&callbacks);
}

bool connection::connect(user &user, server &server) {
    if(!session) return false;
    irc_connect(session, server.get_address().c_str(), 0, 0,
                user.get_nick().c_str(), user.get_nick2().c_str(),
                user.get_fullname().c_str());
    return true;
}

void connection::disconnect() {
    irc_disconnect(session);
    irc_destroy_session(session);
}

