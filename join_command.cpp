#include "join_command.h"

join_command::join_command()
{

}


void join_command::execute(irc_session_t *session) {
    if ( irc_cmd_join( session, arguments[0].toStdString().c_str(), 0 ) ) {

    }
}


join_command::~join_command()
{

}

