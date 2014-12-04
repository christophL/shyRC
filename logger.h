#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <iostream>

class logger
{
public:
    template<class T>
    static void log(T to_log);

private:
    logger() = default;
};

template<class T>
void logger::log(T to_log){
    std::ofstream logfile("shyRC.log", std::ios::app | std::ios::out);
    if(logfile.is_open()){
        logfile << to_log << std::endl;
        logfile.close();
    }
}

#endif // LOGGER_H
