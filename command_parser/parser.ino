
#include "command_parser.h"

void Parser::parse()
{
    
    while (!Serial.available())
        ;
    String input = Serial.readString();
    int arg = 0, next = 0;

    for (int i = 0; i < input.length(); i++)
    {
        if (input.charAt(i) == ' ')
        {
            argv[arg] = input.substring(next, i);
            next = i + 1;
            arg++;
        }
        else if (input.charAt(input.length() - 1))
        {
            argv[arg] = input.substring(next, i);
        }
    }
}

void Parser::add_command(String command_name, String command_desc)
{
}

void Parser::execute(String command, void (*callback)(Parser *))
{
    if (command == argv[0])
    {
        callback(this);
    }
}