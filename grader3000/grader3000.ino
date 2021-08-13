void setup()
{
  Serial.begin(9600);

  Assignment a = Assignment();
  // put your setup code here, to run once:
}

void loop()
{
  // put your main code here, to run repeatedly:
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
  String subcommand = args[1];

  if (command == "age")
  {
  }
  else if (command == "help")
  {
    Serial.println("Welcome to the help center! \n This program uses a command parser for user interaction \n Below is a list of commands and subcommands. \n Add assignment (teacher) [teacher add <assignment-name> <assingnment-body>] \n Remove assingment [teacher rm <assingment-name>] \n Grade assingnment [teacher grd <assingment-name> <score>] \n View assignment [teacher view <assingment-name] \n Help [help] \n kill [kill]");
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

class Assignment
{
public:
  String name;
  String body;
  float grade;
  void add_grade(float score);

};



void Assignment::add_grade(float score)
{
  this->grade = score;
}

String create_assignment(String name, String body, Assignment a)
{
  a.name = name;
  a.body = body;
  return "Assignment " + a.name + " created with body: " + a.body;
}

