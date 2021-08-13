#pragma once

#include "arg.h"
#include "flag.h"
class Command
{
public:
    String command_name;
    String command_desc;
    Arg args[10];
    Flag flags[4];
};
