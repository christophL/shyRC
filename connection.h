#ifndef CONNECTION_H
#define CONNECTION_H
#include "server.h"
#include "user.h"
#include "libircclient.h"
#include <string>
#include <cstring>
#include <cstdio>
#include <QObject>

class connection;
typedef struct
{
    const char *nick;
    connection *conn;

} irc_ctx_t;

class connection : public QObject
{
    Q_OBJECT

public:
    connection();
    ~connection();
    bool connect(user &user, server &server);
    void disconnect();
signals:
    void text_received(QString received);
private:
    irc_session_t *session;
    irc_callbacks_t callbacks;
    irc_ctx_t ctx;
    void run(irc_session_t *session);
    static void event_connect(irc_session_t *session, const char *event, const char *origin, const char **params, unsigned count);
    static void event_numeric(irc_session_t *session, unsigned event, const char *origin, const char **params, unsigned count);
    static void dump_event (irc_session_t *session, const char *event, const char *origin, const char **params, unsigned count);
};

#endif // CONNECTION_H
