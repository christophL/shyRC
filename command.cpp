#include "command.h"
#include "join_command.h"
#include "msg_command.h"

command::command()
{

}

std::unique_ptr<command> command::create(QString channel, QString parameters){
    if(parameters.startsWith('/')){
        QStringList parameterlist = parameters.split(" ");
        if(parameterlist[0] == "/join") {
            std::unique_ptr<command> cmd(new join_command());
            for (int i = 1; i < parameterlist.length(); i++) {
                cmd->arguments.append(parameterlist[i]);
            }
            return cmd;
        }
    } else { //a message command
        if(channel == nullptr) return nullptr;
        std::unique_ptr<command> cmd(new msg_command());
        cmd->arguments.append(channel);
        cmd->arguments.append(parameters);
        return cmd;
    }
    return nullptr;
}

command::~command()
{

}

