
/*
  Rafayel Amirkhanyan 

*/
void setup()
{
  Serial.begin(9600);
  Serial.println("Welcome to Morse, \n Enter your name and watch the light blink out your name in morse code!");

  pinMode(13, OUTPUT);
  while(!Serial.available());
  morse_letter(Serial.readString(), 300, 1000);
}

void loop()
{
}



void morse_letter(String name, unsigned long delay_time, unsigned long delay_between)
{
  name.toUpperCase();

  for (int i = 0; i < name.length(); i++)
  {
    switch (name.charAt(i))
    {
    case 'A':
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      break;
    case 'B':
      long_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      break;
    case 'C':
      long_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      break;
    case 'D':
      long_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      break;
    case 'E':
      short_blink();
      delay(delay_time);
      break;
    case 'F':
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      break;
    case 'G':
      long_blink();
      delay(delay_time);
      long_blink();
      short_blink();
      delay(delay_time);
      break;
    case 'H':
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      break;
    case 'I':
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      break;
    case 'J':
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      break;
    case 'K':
      long_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      break;
    case 'L':
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      break;
    case 'M':
      long_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      break;
    case 'N':
      long_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      break;
    case 'O':
      long_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      break;
    case 'P':
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      break;
    case 'Q':
      long_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      break;
    case 'R':
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      short_blink();
      break;
    case 'S':
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      break;
    case 'T':
      long_blink();
      delay(delay_time);
      break;
    case 'U':
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      break;
    case 'V':
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      break;
    case 'W':
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      break;
    case 'X':
      long_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      break;
    case 'Y':
      long_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      break;
    case 'Z':
      long_blink();
      delay(delay_time);
      long_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      short_blink();
      delay(delay_time);
      break;
    }
    delay(delay_between);
  }
}

void short_blink()
{
  digitalWrite(13, HIGH);
  delay(50);
  digitalWrite(13, LOW);
}

void long_blink()
{
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
}

// void blink()
// {
//   digitalWrite(13, HIGH);
//   delay(5);
//   digitalWrite(13, LOW);
// }
