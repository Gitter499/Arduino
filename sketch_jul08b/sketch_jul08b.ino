void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Welcome to coin flipper, write flip to \"flip\" a coin");
  while (!Serial.available())
    ;

  while (true)
  {
    String input = Serial.readString();

    if (parseArgs(input, "flip"))
    {
      int num = random(1, 3);

      if (num == 1)
      {
        Serial.println("Heads");
      }
      else if (num == 2)
      {
        Serial.println("Tails");
      }
    }
    else
    {
      Serial.println("Command not recognized");
    }
  }
}

bool parseArgs(String args, String match)
{
  if (match.length() == args.length())
  {
    for (int i = 0; i < args.length(); i++)
    {
      if (args[i] == match[i])
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }
  else
  {
    return false;
  }
}

enum ArgTypes
{
  COMMAND,
  OPTION
};

void loop()
{
  // put your main code here, to run repeatedly:
}
