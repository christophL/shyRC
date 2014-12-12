#ifndef BASEUSER_H
#define BASEUSER_H

#include <string>
#include <map>
#include <set>

#include "server.h"
#include "channel.h"


class baseuser {
private:
    std::string fullname;
    std::string username;
    std::string nick;
    std::string nick2;
    std::string nick3;
    std::map<server, std::set<std::string>> favorite_channels;
public:
    virtual void set_fullname(std::string name);
    virtual void set_username(std::string username);
    virtual void set_nick(std::string nick);
    virtual void set_nick2(std::string nick2);
    virtual void set_nick3(std::string nick3);
    virtual const std::string &get_fullname() const;
    virtual const std::string &get_username() const;
    virtual const std::string &get_nick() const;
    virtual const std::string &get_nick2() const;
    virtual const std::string &get_nick3() const;
    virtual bool add_favorite_channel(server& server, std::string channel);
};

#endif // BASEUSER_H
