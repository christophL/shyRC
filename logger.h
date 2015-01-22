#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <iostream>

enum level { ERROR, DEBUG, OTHER };

template <int N>
class logger
{
public:
    template<class T>
    static void log(T to_log);

private:
    logger() = default;
};

template<int N>
template<class T>
void logger<N>::log(T to_log){
    std::string file_type = "";
    switch(N){
    case ERROR: file_type = "_error"; break;
    case DEBUG: file_type = "_debug"; break;
    }
    std::ofstream logfile("shyRC" + file_type + ".log", std::ios::app | std::ios::out);
    if(logfile.is_open()){
        logfile << to_log << std::endl;
        logfile.close();
    }
}

#endif // LOGGER_H
