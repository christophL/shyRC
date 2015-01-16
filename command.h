#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <memory>
#include <QStringList>
#include "libircclient.h"

class command
{
protected:
    command();
    QStringList arguments;
public:
    static std::unique_ptr<command> create(QStringList parameterlist);
    virtual void execute(irc_session_t *session) = 0;
    ~command();
};

#endif // COMMAND_H
