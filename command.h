#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <memory>
#include "libircclient.h"

class command
{
protected:
    command();
public:
    static std::unique_ptr<command> create(std::string name);
    virtual void execute(irc_session_t *session) = 0;
    ~command();
};

#endif // COMMAND_H
