#include "command.h"
#include "join_command.h"

command::command()
{

}

std::unique_ptr<command> command::create(QStringList parameterlist){
    if(parameterlist[0] == "/join") {
        std::unique_ptr<command> cmd(new join_command());
        for (int i = 1; i < parameterlist.length(); i++) {
            cmd->arguments.append(parameterlist[i]);
        }
        return cmd;
    } else {
        return nullptr;
    }
}

command::~command()
{

}

