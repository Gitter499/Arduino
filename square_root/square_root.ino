#include "parser.h"

void setup()
{
  // put your setup code here, to run once:
  while (!Serial.available())
    ;

  if (1)
  {
    Serial.println("Hello World");
  }
  // while (true)
  // {

  //     String args[4];

  //     String input = Serial.readString();

  //     String command = parser(input, args);

  //     if (command == "sqrt")
  //     {
  //       Serial.println("Command ran");
  //       int arg = args[1].toInt();

  //       isSquare(arg);
  //     }
  //   }
}

void isSquare(int n)
{
  for (int i = 1; i * i <= n; i++)
  {
    if (n < 1)
    {
      Serial.println("Not a perfect square!");
    }
    else
    {
      if (i * i == n)
      {
        Serial.println("Perfect square!");
      }
      else
      {
        Serial.println("Not a perfect square!");
      }
    }
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
}
