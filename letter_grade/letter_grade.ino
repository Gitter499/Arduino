void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Welcome to grademaster. \n Type a command <format> <value> \n Type \"help\" for help \n");
}

void loop()
{
  // put your main code here, to run repeatedly:
  while (!Serial.available())
    ;
  String input = Serial.readString();

  int arg = 0, next = 0;

  String args[2];

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

  if (command == "grade")
  {
    float value = args[1].toFloat();

    if (value == 0)
    {
      Serial.println("Go home bro");
    }
    else if (value > 0 && value <= 55)
    {
      Serial.println("F");
    }
    else if (value <= 65 && value > 55)
    {
      Serial.println("D");
    }
    else if (value <= 75 && value >= 65)
    {
      Serial.println("C");
    }
    else if (value <= 85 && value >= 75)
    {
      Serial.println("B");
    }
    else if (value < 90 && value >= 85)
    {
      Serial.println("A-");
    }
    else if (value >= 90 && value <= 100)
    {
      Serial.println("A");
    }
    else if (value > 100)
    {
      Serial.println("Hmmmmmmm....");
    }
    else
    {
      Serial.println("You shouldn't see this");
    }
  }
  else if (command == "help")
  {
    Serial.println("Type in the tempature you want to convert from then the value seperated by a space. \n Example: grade 78, grade 90, grade 12 \n Type \"kill\" to kill this program");
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
