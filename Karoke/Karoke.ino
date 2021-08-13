
#include <LiquidCrystal.h> //the liquid crystal library contains commands for printing to the display


LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int buzzerPin = 7;

String lyrics  = "We\'re no strangers to love. You know the rules and so do I. A full commitment\'s what I\'m thinking of you wouldn\'t get this from any other guy   ";

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(buzzerPin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print(lyrics);
  delay(1000);
}

void loop()
{
  for (int PositionCount = 0; PositionCount < 13; PositionCount++) //loop for scrolling the LCD text
  {
    lcd.scrollDisplayLeft();//builtin command to scroll left the text
    delay(150);// delay of 150 msec
  }

  tone(buzzerPin, 424);
}
