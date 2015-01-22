#ifndef MSG_COMMAND_H
#define MSG_COMMAND_H

#include "command.h"
#include "connection.h"

class msg_command : public command
{
    friend class command;
private:
    msg_command();
public:
    void execute(irc_session_t *session) override;
    ~msg_command();
};

#endif // MSG_COMMAND_H
