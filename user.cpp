#include "user.h"

using namespace std;

user::user(string fullname, string nick)
    : fullname(fullname), nick(nick) {
}

string user::get_fullname(){
    return fullname;
}

string user::get_nick(){
    return nick;
}

string user::get_nick2(){
    return nick2;
}

string user::get_nick3(){
    return nick3;
}

void user::set_fullname(string name){
    this->fullname = name;
}

void user::set_nick(string nick){
    this->nick = nick;
}

void user::set_nick2(string nick2){
    this->nick2 = nick2;
}

void user::set_nick3(string nick3){
    this->nick3 = nick3;
}

bool user::add_favorite_channel(server& serv, string channel){
    return favorite_channels[serv].insert(channel).second;
}
