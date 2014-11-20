#include "connection.h"

typedef struct
{
    char 	* channel;
    char 	* nick;

} irc_ctx_t;

void dump_event (irc_session_t *session, const char * event, const char * origin, const char ** params, unsigned int count) {
    char buf[512];
    int cnt;

    buf[0] = '\0';

    for ( cnt = 0; cnt < count; cnt++ ) {
        if ( cnt ) {
            strcat (buf, "|");
        }
        strcat (buf, params[cnt]);
    }
}

void event_numeric(irc_session_t *session, unsigned int event, const char * origin, const char ** params, unsigned int count) {
    char buf[24];
    sprintf (buf, "%d", event);

    dump_event (session, buf, origin, params, count);
}

void event_connect(irc_session_t *session, const char * event, const char * origin, const char ** params, unsigned int count) {
    irc_ctx_t * ctx = (irc_ctx_t *) irc_get_ctx (session);
    dump_event (session, event, origin, params, count);

    irc_cmd_join (session, ctx->channel, 0);
}


connection::connection() {

}

void connection::connect() {

    irc_callbacks_t callbacks;
    memset (&callbacks, 0, sizeof(callbacks));

    callbacks.event_connect = event_connect;
    callbacks.event_numeric = event_numeric;

    connection::session = irc_create_session(&callbacks);

    irc_connect(session, "irc.rizon.net", 0, 0, "nickriririririririririr", "user", "name");

}

void connection::disconnect() {

    irc_disconnect(connection::session);

    irc_destroy_session(connection::session);

}

irc_session_t *connection::getSession() {
    return session;
}

