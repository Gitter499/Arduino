void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Welcome to age master \ntype in your age with the age command followed by your (real ;) age seperated by space \n Type \"help\" to get help");
}

void check_age(int age)
{
  if (age < 13)
  {
    Serial.println("Enjoy life kid!");
  }
  else if (age >= 13 && age < 16)
  {
    Serial.println("Welcome to your teenage years \n You CAN'T drink OR drive");
  }
  else if (age >= 16 && age < 18)
  {
    Serial.println("You can drive but not drink");
  }
  else if (age >= 21)
  {
    Serial.println("You can drink, you can also drive, but you can't do both! \n Be responsible!");
  }
  else
  {
    Serial.println("You shouldn't see this message :(");
  }
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

  if (command == "age")
  {
    int age = args[1].toInt();

    // Age checker
    check_age(age);
  }
  else if (command == "help")
  {
    Serial.println("This program uses a command parser \n Type a command (age <value>, help, kill) to interact! \n Example: age 18, help, age 21, kill \n The command kill ends the program");
  }
  else if (command == "kill")
  {
    Serial.println("Bye Bye!");
    delay(500);
    exit(0);
  }
  else
  {
    Serial.println("Command not recognized \n Type \"help\" for help");
  }
}
