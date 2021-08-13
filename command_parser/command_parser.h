#pragma once

#include "command.h"

class Parser
{
public:
    String argv[15];
    Command commands[5];

    // Commands
    // Command App Credentials
    String app_name;
    // Options
    bool help_msg = false;
    String help_string;
    Parser(String name)
    {
        this->app_name = name;
        this->help_msg = help_msg;

        // if (help_msg)
        // {
            
        //     for (int i = 0; i < sizeof commands; i++)
        //     {
        //         help_string += "Welcome to " + app_name + " help center" + "\nCommands: " + "\n " + commands[i].command_name + "\n " + commands[i].command_desc + "\n";
        //     }
        // }
    }
    void add_command(String command_name, String command_desc);
    void parse();
    void execute(String command, void (*callback)(Parser*));
};
