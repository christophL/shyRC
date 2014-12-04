#ifndef SERVER_H
#define SERVER_H

#include <string>


class server {
private:
    std::string name;
    std::string address;
    uint16_t port;
public:    
    server() = default;
    server(std::string name);
    void set_name(std::string name);
    bool set_address(std::string address, uint16_t port = 6667);
    const std::string &get_name() const;
    const std::string &get_address() const;
    uint16_t get_port() const;
    bool operator==(const server& other) const;
    bool operator!=(const server& other) const;
    bool operator<(const server& other) const;
};

#endif // SERVER_H
