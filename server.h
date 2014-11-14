#ifndef SERVER_H
#define SERVER_H

#include <string>


class server {
private:
    std::string name;
    std::string ipv4;
    uint16_t port;
public:    
    server() = default;
    server(std::string name);
    void set_name(std::string name);
    bool set_ip(std::string ipv4, uint16_t port);
    std::string get_name() const;
    std::string get_ipv4() const;
    uint16_t get_port() const;
    bool operator==(const server& other) const;
    bool operator!=(const server& other) const;
    bool operator<(const server& other) const;
};

#endif // SERVER_H
