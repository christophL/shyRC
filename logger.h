#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <iostream>

class logger
{
public:
    static void log(std::string to_log);

private:
    logger() = default;
};

#endif // LOGGER_H
