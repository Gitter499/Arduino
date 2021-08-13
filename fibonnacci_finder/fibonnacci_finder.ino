
void setup()
{
  Serial.begin(9600);
  Serial.println("Welcome to fib master \n Type \"help\" to get help");
  // put your setup code here, to run once:

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

    if (command == "fib")
    {
      Serial.println("Fib ran");
      int val = args[1].toInt();
      fibonacci(val);
    }
    else if (command == "sufib")
    {
      int val = args[1].toInt();
      second_fib(val);
    }
    else if (command == "help")
    {
      Serial.println("Type in \"fib\" then the value seperated by a space. \n Example: fib 78, fib 90, fib 12 \n Type \"kill\" to kill this program");
    }
    else if (command == "kill")
    {
      Serial.println("Bye Bye!");
      delay(500);
      exit(0);
    }
    else if (command == "evens")
    {
      int val = args[1].toInt();
      even_number_gen(val);
    }
    else if (command == "fac")
    {
      int val = args[1].toInt();
      Serial.println((String)factorial(val));
    }
    else if (command == "refac")
    {
      int val = args[1].toInt();
      Serial.println((String)recursive_factorial(val));
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

void fibonacci(int n)
{
  int first = 0, next = 0, second = 1;
  Serial.println("Fib series: ");

  for (int i = 1; i <= n; ++i)
  {

    if (i == 1)
    {
      Serial.println((String)first + ",");
      continue;
    }
    if (i == 2)
    {
      Serial.println((String)second + ",");
      continue;
    }
    next = first + second;
    first = second;
    second = next;
    Serial.println((String)next + ", ");
  }
}

void second_fib(long n)
{
  long first = 0, next = 0, second = 1;
  Serial.println((String)first + ",");
  Serial.println((String)second + ",");
  while (n != 0)
  {
    next = first + second;
    first = second;
    second = next;
    Serial.println((String)next + ", ");
    n--;
  }
}

void even_number_gen(int n)
{
  for (int i = 0; i <= n; i++)
  {
    if (i % 2 == 0)
    {
      Serial.println((String)i);
    }
  }
}

int factorial(int n)
{
  unsigned int f = 1;
  for (int i = 1; i <= n; i++)
  {
    f *= i;
  }
  return f;
}

int recursive_factorial(long n)
{
  if (n >= 1)
  {

    return (n * recursive_factorial(n - 1));
  }
  else
  {
    return 1;
  }
}
