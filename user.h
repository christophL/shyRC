#ifndef USER_H
#define USER_H

#include <string>
#include <map>
#include <set>

#include "server.h"
#include "channel.h"
#include "baseuser.h"

class user : public baseuser {
private:
    std::string fullname;
    std::string username;
    std::string nick;
    std::string nick2;
    std::string nick3;
    std::map<server, std::set<std::string>> favorite_channels;
public:
    user() = default;
    user(std::string fullname, std::string nick);
    void set_fullname(std::string name) override;
    void set_username(std::string username) override;
    void set_nick(std::string nick) override;
    void set_nick2(std::string nick2) override;
    void set_nick3(std::string nick3) override;
    const std::string &get_fullname() const override;
    const std::string &get_username() const override;
    const std::string &get_nick() const override;
    const std::string &get_nick2() const override;
    const std::string &get_nick3() const override;
    bool add_favorite_channel(server& server, std::string channel) override;
};

#endif // USER_H
