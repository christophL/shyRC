#ifndef SERVER_H
#define SERVER_H

#include <string>

using namespace std;

class server {
private:
    string name;
    string ipv4;
    int port;
public:    
    server() = default;
    server(string name, string ipv4, int port);
};

#endif // SERVER_H
