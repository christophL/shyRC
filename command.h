#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <memory>
#include <QStringList>
#include "libircclient.h"

class command
{
protected:
    command() = default;
    QStringList arguments;
public:
    static std::unique_ptr<command> create(QString channel, QString parameters);
    virtual void execute(irc_session_t *session) = 0;
};

#endif // COMMAND_H
