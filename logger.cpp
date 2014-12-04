#include "logger.h"

using namespace std;

void logger::log(string to_log){
    ofstream logfile("shyRC.log", ios::app | ios::out);
    if(logfile.is_open()){
        logfile << to_log << endl;
        logfile.close();
    }
}
