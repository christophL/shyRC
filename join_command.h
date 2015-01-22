#ifndef JOIN_COMMAND_H
#define JOIN_COMMAND_H

#include "command.h"

class join_command : public command
{
    friend class command;
private:
    join_command() = default;
public:
    void execute(irc_session_t *session) override;
};

#endif // JOIN_COMMAND_H
