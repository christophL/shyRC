#ifndef MSG_COMMAND_H
#define MSG_COMMAND_H

#include "command.h"
#include "connection.h"

class msg_command : public command
{
    friend class command;
private:
    msg_command() = default;
public:
    void execute(irc_session_t *session) override;
};

#endif // MSG_COMMAND_H
