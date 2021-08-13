#pragma once

String parser(String input, String *argv)
{
   

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
    return argv[0];
}
