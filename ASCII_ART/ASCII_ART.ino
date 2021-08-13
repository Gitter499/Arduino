void setup()
{
  Serial.begin(9600);
  int rows;
  while (true)
  {
    while (!Serial.available())
      ;

    String input = Serial.readString();

    int arg = 0, next = 0;

    String args[4];

    for (int i = 0; i < input.length(); i++)
    {
      if (input.charAt(i) == ' ')
      {
        args[arg] = input.substring(next, i);
        next = i + 1;
        arg++;
      }
      else if (input.charAt(input.length() - 1))
      {
        args[arg] = input.substring(next, i);
      }
    }
    String command = args[0];

    if (args[1] == "width")
    {
      rows = args[2].toInt();
    }

    if (command == "pyramid")
    {
      pyramid(rows);
    }
    else if (command == "star")
    {
      
    }
    else if (command == "help")
    {
      Serial.println("Type in the shape that you want plus the width. \nExample: pyramid width 5, star width 12 \n Type \"kill\" to kill this program");
    }
    else if (command == "kill")
    {
      Serial.println("Bye Bye!");
      delay(500);
      exit(0);
    }
    else
    {
      Serial.println("Command not found");
    }
  }
}

void loop()
{
}

void pyramid(int rows)
{
  for (int i = 1; i <= rows; i++)
  {
    // Red
    for (int j = rows - i; j > 0; j--)
    {
      Serial.print(" ");
    }

    // Yellow
    for (int j = 1; j <= i; j++)
    {
      Serial.print("*");
    }
    // Blue

    for (int j = 1; j < i; j++)
    {
      Serial.print("*");
    }
    Serial.print("\n");
  }
}
