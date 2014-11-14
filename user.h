#ifndef USER_H
#define USER_H

#include <string>
#include <map>
#include <set>

#include "server.h"
#include "channel.h"


class user {
private:
    std::string fullname;
    std::string nick;
    std::string nick2;
    std::string nick3;
    std::map<server, std::set<std::string>> favorite_channels;
public:
    user() = default;
    user(std::string fullname, std::string nick);
    void set_fullname(std::string name);
    void set_nick(std::string nick);
    void set_nick2(std::string nick2);
    void set_nick3(std::string nick3);
    std::string get_fullname() const;
    std::string get_nick() const;
    std::string get_nick2() const;
    std::string get_nick3() const;
    bool add_favorite_channel(server& server, std::string channel);
};

#endif // USER_H
