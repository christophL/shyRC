#ifndef USER_H
#define USER_H

#include <string>
#include <map>

#include "server.h"
#include "channel.h"


using namespace std;

class user {
private:
    string fullname;
    string nick;
    map<server, channel> favorite_channels;
public:
    user() = default;
    user(string fullname, string nick);
};

#endif // USER_H
