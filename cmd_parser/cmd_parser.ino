
void compare(float value, String conv_type)
{
  if (conv_type.equals("ktc"))
  {
    Serial.println("Celsius: " + (String)(value - 273.15) + "\n");
  }
  else if (conv_type.equals("ktf"))
  {
    Serial.println("Farenheit: " + (String)((((value - 273.15) * 9) / 5) + 32) + "\n");
  }
  else if (conv_type.equals("ctk"))
  {
    Serial.println("Kelvin: " + (String)(value + 273.15) + "\n");
  }
  else if (conv_type.equals("ctf"))
  {
    Serial.println("Farenheit: " + (String)((value * (9 / 5)) + 32) + "\n");
  }
  else if (conv_type.equals("ftk"))
  {
    Serial.println("Kelvin: " + (String)(((value - 32) / 1.8) + 273.15) + "\n");
  }
  else if (conv_type.equals("ftc"))
  {
    Serial.println("Celsius: " + (String)((value - 32) / 1.8) + "\n");
  }
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("");
  Serial.println("Welcome to tempmaster, the ultimate temp converting technology. \n Type a command <format> <value> \n Type \"help\" for help \n");
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

  if (command == "kelvin")
  {

    float kelvin = args[1].toFloat();

    compare(kelvin, "ktc"); // (type)t(final_type)

    compare(kelvin, "ktf");
    Serial.println("---------------------------");
  }
  else if (command == "celsius")
  {

    float celsius = args[1].toFloat();

    compare(celsius, "ctk"); // (type)t(final_type)

    compare(celsius, "ctf");
    Serial.println("---------------------------");
  }
  else if (command == "farenheit")
  {
    float farenheit = args[1].toFloat();

    compare(farenheit, "ftk"); // (type)t(final_type)

    compare(farenheit, "ftc");
    Serial.println("---------------------------");
  }
  else if (command == "help")
  {
    Serial.println("Type in the tempature you want to convert from then the value seperated by a space. \n Example: kelvin 80, celsius 37, farenheit 80 \n Type \"kill\" to kill this program");
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
