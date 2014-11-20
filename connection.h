#ifndef CONNECTION_H
#define CONNECTION_H

#include "libircclient.h"
#include <cstring>
#include <stdio.h>

class connection
{
public:
    connection();
    void connect();
    void disconnect();
    irc_session_t *getSession();
private:
    irc_session_t *session;
};

#endif // CONNECTION_H
