int firstKeyPin = 2;
int secondKeyPin = 3;
int thirdKeyPin = 4;

int buzzerPin = 10;

void setup()
{
  // put your setup code here, to run once:
  pinMode(firstKeyPin, INPUT_PULLUP);
  pinMode(secondKeyPin, INPUT_PULLUP);
  pinMode(thirdKeyPin, INPUT_PULLUP);

  //set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  String binary = "";
  if (digitalRead(firstKeyPin) == LOW)
  {
    binary += '0';
  }
  else if (digitalRead(secondKeyPin) == LOW)
  {
    binary += '1';
  }
  else if (digitalRead(thirdKeyPin) == LOW)
  {
    binary += ' ';
  }

  if (binary.length() == 40)
  {
    String binaries[10];
    int integer_arr[10];
    String final_string;
    stringToArray(binary, binaries);

    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        integer_arr[i] += (int)binaries[i].charAt(j);
      }
      final_string += (char)integer_arr[i];
    }

    play(final_string);
  }
}
void stringToArray(String result, String *arr)
{
  int pos = 0, nextElem = 0;

  for (int i = 0; i < result.length(); i++)
  {
    if (result.charAt(i) == ' ')
    {
      arr[pos] = result.substring(nextElem, i).toInt();
      nextElem = i + 1;
      pos++;
    }
    else if (result.charAt(result.length() - 1))
    {
      arr[pos] = result.substring(nextElem, i).toInt();
    }
  }
}

void play(String notes)
{
  notes.toUpperCase();

  for (int i = 0; i < notes.length(); i++)
  {
    switch (notes.charAt(i))
    {
    case 'c':
      tone(buzzerPin, 262);
      break;
    case 'd':
      tone(buzzerPin, 294);
      break;
    case 'e':
      tone(buzzerPin, 330);
      break;
    case 'f':
      tone(buzzerPin, 349);
      break;
    case 'g':
      tone(buzzerPin, 392);
      break;
    case 'a':
      tone(buzzerPin, 440);
      break;
    case 'b':
      tone(buzzerPin, 494);
      break;
    case 'C':
      tone(buzzerPin, 523);
      break;

    default:
      noTone(buzzerPin);
    }
  }
}

/*
  note  frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz
*/