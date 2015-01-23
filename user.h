#ifndef USER_H
#define USER_H

#include <string>
#include <map>
#include <set>
#include <algorithm>

#include "server.h"

template<typename T>
struct hugo{
    T x;
    hugo(T c) { x = c; }
    bool operator()(T c){ return c == x; }
};

class user {
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
    void set_fullname(std::string name);
    void set_username(std::string username);
    void set_nick(std::string nick);
    void set_nick2(std::string nick2);
    void set_nick3(std::string nick3);
    const std::string &get_fullname() const;
    const std::string &get_username() const;
    const std::string &get_nick() const;
    const std::string &get_nick2() const;
    const std::string &get_nick3() const;
    bool add_favorite_channel(server& server, std::string channel);

    std::string do_stuff(){
        std::string blah(nick);
        std::for_each(blah.begin(), blah.end(), [](char &c){c++;});
        return blah;
    }

    int count_stuff(char blah) const{
        return std::count_if(nick.begin(), nick.end(), hugo<char>(blah));
    }
};

#endif // USER_H
