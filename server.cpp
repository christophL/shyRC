#include "server.h"

#include<regex>

using namespace std;

server::server(string name) : name(name){

}

string server::get_name() const{
    return name;
}

string server::get_ipv4() const{
    return ipv4;
}

uint16_t server::get_port() const{
    return port;
}

bool server::set_ip(string ipv4, uint16_t port){
    regex ip_regex("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    if(!regex_match(ipv4, ip_regex)) return false;
    this->ipv4 = ipv4;
    this->port = port;
    return true;
}

void server::set_name(string name){
    this->name = name;
}

bool server::operator ==(const server& other) const{
    if(name != other.name) return false;
    else if(ipv4 == other.ipv4 && port == other.port) return true;
    return false;
}

bool server::operator !=(const server& other) const{
    return !(*this == other);
}

bool server::operator <(const server& other) const{
    return name < other.name;
}
