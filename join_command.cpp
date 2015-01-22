#include "join_command.h"

void join_command::execute(irc_session_t *session) {
    if ( irc_cmd_join( session, arguments[0].toStdString().c_str(), 0 ) ) {

    }
}


