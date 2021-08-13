void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);

  Serial.println("Welcome to Powerhouse, type a base then a power");

  while (!Serial.available());

  float base = Serial.readString().toFloat();

  Serial.println("Base recieved as: " + (String)base);
  while (!Serial.available());
  float expo = Serial.readString().toFloat();

  Serial.println("Powered recieved as: " + (String)expo);

  float result = pow(base, expo);

  Serial.println("Result: " + (String)result);


}

bool parse(String input, String match)
{
  if (input.length() == match.length())
  {
    for (int i = 0; i < input.length(); i++)
    {
      if (input[i] == match[i])
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

void loop()
{
  // put your main code here, to run repeatedly:
}
