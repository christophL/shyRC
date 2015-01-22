#include "msg_command.h"


void msg_command::execute(irc_session_t *session){
    if(irc_cmd_msg(session, arguments[0].toStdString().c_str(), arguments[1].toStdString().c_str())){}
    irc_ctx_t *ctx = static_cast<irc_ctx_t *>(irc_get_ctx(session));
    emit(ctx->conn->text_received(QString(arguments[0] + ": " + arguments[1])));
}

