#include "command_parser.h"

Parser p = Parser("Test app");

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);

  Serial.println(p.app_name + " \n Type \"help\" to get help");
}

void loop()
{
  // put your main code here, to run repeatedly:

}
