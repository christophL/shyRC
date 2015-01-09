#include "command.h"
#include "join_command.h"

command::command()
{

}

std::unique_ptr<command> command::create(std::string name){
    if(name == "/join"){
        return std::unique_ptr<command>(new join_command());
    } else {
        return nullptr;
    }
}

command::~command()
{

}

