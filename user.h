#ifndef USER_H
#define USER_H

#include <string>
#include <map>
#include <set>

#include "server.h"
#include "channel.h"


using namespace std;

class user {
private:
    string fullname;
    string nick;
    string nick2;
    string nick3;
    map<server, set<string>> favorite_channels;
public:
    user() = default;
    user(string fullname, string nick);
    void set_fullname(string name);
    void set_nick(string nick);
    void set_nick2(string nick2);
    void set_nick3(string nick3);
    string get_fullname();
    string get_nick();
    string get_nick2();
    string get_nick3();
    bool add_favorite_channel(server server, string channel);
};

#endif // USER_H
