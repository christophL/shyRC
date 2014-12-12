#include "baseuser.h"

using namespace std;


const string &baseuser::get_fullname() const{
    return fullname;
}

const string &baseuser::get_username() const{
    return username;
}

const string &baseuser::get_nick() const{
    return nick;
}

const string &baseuser::get_nick2() const{
    return nick2;
}

const string &baseuser::get_nick3() const{
    return nick3;
}

void baseuser::set_fullname(string name){
    this->fullname = name;
}

void baseuser::set_username(string username){
    this->username = username;
}

void baseuser::set_nick(string nick){
    this->nick = nick;
}

void baseuser::set_nick2(string nick2){
    this->nick2 = nick2;
}

void baseuser::set_nick3(string nick3){
    this->nick3 = nick3;
}

bool baseuser::add_favorite_channel(server& serv, string channel){
    return favorite_channels[serv].insert(channel).second;
}
