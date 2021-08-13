void setup()
{
  Serial.begin(9600);

  Serial.println("Welcome to SuperMax, \n Type \"help\" to get help");

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

    if (command == "max")
    {

      int first_num = args[1].toInt();
      int second_num = args[2].toInt();
      String third_num = args[3];

      find_max(first_num, second_num, third_num.toInt(), third_num);
    }
    else if (command == "help")
    {
      Serial.println("Type in max then the 3  (or 2)values seperated by space. \nExample: max 5 12 56, max 14 16 \n Type \"kill\" to kill this program");
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
  // put your main code here, to run repeatedly:
}

void find_max(int first_num, int second_num, int third_num, String last_arg)
{
  int max;
  if (last_arg == "")
  {
    max = max(first_num, second_num);
  }
  else if (first_num > second_num && first_num > third_num)
  {
    max = first_num;
  }
  else if (second_num > third_num)
  {
    max = second_num;
  }
  else
  {
    max = third_num;
  }
  Serial.println("Your max is " + (String)max);
}