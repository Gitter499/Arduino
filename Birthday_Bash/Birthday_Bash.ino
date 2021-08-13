
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Welcome to Birthday Bash. \n Type a command <format> <value> \n Type \"help\" for help \n");
}

void parse_dates(String date, int *date_arr)
{
  int pos = 0, nextElem = 0;

  for (int i = 0; i < date.length(); i++)
  {
    if (date.charAt(i) == '/')
    {
      date_arr[pos] = date.substring(nextElem, i).toInt();
      nextElem = i + 1;
      pos++;
    }
    else if (date.charAt(date.length() - 1))
    {
      date_arr[pos] = date.substring(nextElem, i).toInt();
    }
  }
}

void holidays(String holiday_name, int holiday_month, int holiday_day, int *arr)
{
  if (arr[0] == holiday_month)
  {
    int days = holiday_day - arr[1];

    if (days < 0)
    {

      Serial.println(holiday_name + " was " + (String)abs(days) + " days ago \n");
    }
    else
    {
      Serial.println(holiday_name + " is " + (String)days + " days away \n");
    }
  }
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

  if (command == "bday")
  {
    String current_date = args[1];
    String user_birthday = args[2];
    String holiday_opt = args[3];

    int curr_date_arr[3];
    int user_date_arr[3];

    parse_dates(current_date + '/', curr_date_arr);
    parse_dates(user_birthday + '/', user_date_arr);

    // Check if user provided valid dates

    if (curr_date_arr[0] > 12 || curr_date_arr[1] > 31 || user_date_arr[0] > 12 || user_date_arr[1] > 31)
    {
      Serial.println("What planet are you living on? \n");
      return;
    }
    else if (curr_date_arr[0] < 0 || curr_date_arr[1] < 0 || user_date_arr[0] < 0 || user_date_arr[1] < 0)
    {
      Serial.println("You can't have negative dates dummy \n");
      return;
    }

    // Landmarks

    if (holiday_opt.startsWith("-h"))
    {
      holidays("Christmas", 12, 25, curr_date_arr);
      holidays("New Years", 1, 1, curr_date_arr);
    }

    // Find the difference
    int month = curr_date_arr[0] - user_date_arr[0];
    int day = curr_date_arr[1] - user_date_arr[1];
    int year = curr_date_arr[2] - user_date_arr[2];

    if (day < 0 || month < 0 || year < 0)
    {
      Serial.println("Stop trying to break my program \n Arduino standard library is stupid and doesn't have date time parsing");
    }

    String month_arr[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    Serial.println("You're " + (String)year + " years, " + (String)month + " months, and " + (String)day + " days old." + " Your month is " + month_arr[user_date_arr[0] - 1] + "\n");
  }
  else if (command == "help")
  {
    Serial.println("Type in the current date followed by your birthday seperated by a space. Use / to format the dates, format is month/day/year. Make sure the current date is first \n Example: bday 7/14/2021 5/17/2006 \n You can also add -h at the end to get holiday reminders \n Type \"kill\" to kill this program");
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
