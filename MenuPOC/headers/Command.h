#ifndef COMMAND_H
#define COMMAND_H

class Command {
    public:
        virtual void execute();
};

void Command::execute() { };

#endif