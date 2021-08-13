

void setup()
{
  Serial.begin(9600);
  Serial.println("Welcome to tempmaster, the ultimate temp converting technology");
  Serial.println("Convert from (enter number corresponding to choice): 1.Kelvin \n 2.Celsius \n 3.Farenheit");

  while (!Serial.available())
    ;

  int input = Serial.readString().toInt();
  String input2 = Serial.readString();

  String args[5] = parser(5, input2);
  String command = args[0];

  if (input == 1)
  {
    Serial.println("Enter Kelvin value");
    while (!Serial.available())
      ;
    float kelvin = Serial.readString().toFloat();

    compare(kelvin, "ktc"); // (type)t(final_type)

    compare(kelvin, "ktf");
  }

  else if (input == 2)
  {
    Serial.println("Enter Celsius value");
    while (!Serial.available())
      ;
    float celsius = Serial.readString().toFloat();

    compare(celsius, "ctk"); // (type)t(final_type)

    compare(celsius, "ctf");
  }

  else if (input == 3)
  {
    Serial.println("Enter Farenheit value");
    while (!Serial.available())
      ;
    float farenheit = Serial.readString().toFloat();

    compare(farenheit, "ftk"); // (type)t(final_type)

    compare(farenheit, "ftc");
  }

  else
  {
    Serial.println("Command not found");
  }
}

void compare(float value, String conv_type)
{
  if (conv_type.equals("ktc"))
  {
    Serial.println("Celsius: " + (String)(value - 273.15));
  }
  else if (conv_type.equals("ktf"))
  {
    Serial.println("Farenheit: " + (String)((((value - 273.15) * 9) / 5) + 32));
  }
  else if (conv_type.equals("ctk"))
  {
    Serial.println("Kelvin: " + (String)(value + 273.15));
  }
  else if (conv_type.equals("ctf"))
  {
    Serial.println("Farenheit: " + (String)((value * (9 / 5)) + 32));
  }
  else if (conv_type.equals("ftk"))
  {
    Serial.println("Kelvin: " + (String)(((value - 32) / 1.8) + 273.15));
  }
  else if (conv_type.equals("ftc"))
  {
    Serial.println("Celsius: " + (String)((value - 32) / 1.8));
  }
}

String parser(int arg_size = 5, String argv)
{
  int arg = 0, next = 0;

  String args[arg_size];

  for (int i = 0; i < argv.length(); i++)
  {
    if (argv.charAt(i) == ' ')
    {
      args[arg] = argv.substring(next, i);
      arg++;
      next = i + 1;
      return args[arg];
    }
  }
}



void
loop()
{
  // put your main code here, to run repeatedly:
}
