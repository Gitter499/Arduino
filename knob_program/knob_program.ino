const int PIN = 13;
int knob_pos;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  knob_pos = analogRead(A0);
  Serial.println(knob_pos);
  digitalWrite(PIN, HIGH);
  delay(knob_pos);
  digitalWrite(PIN, LOW);
  delay(knob_pos);
}
