/*
  SparkFun Inventor’s Kit
  Circuit 4A-HelloWorld

  The LCD will display the words "Hello World" and show how many seconds have passed since
  the RedBoard was last reset.

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

#include <LiquidCrystal.h> //the liquid crystal library contains commands for printing to the display

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // tell the RedBoard what pins are connected to the display

void setup()
{

  lcd.begin(16, 2); //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high

  lcd.print("Rafayel Amirkhanyan Presents ");
  lcd.setCursor(0, 1);
  lcd.print("https://rafayel.codes/");
  delay(1000);
}
void loop()
{

  for (int i = 0; i < 100; i++) //loop for scrolling the LCD text
  {
    lcd.scrollDisplayLeft(); //builtin command to scroll left the text
    delay(150);              // delay of 150 msec
  }
  delay(100);
}
