#include <Servo.h> //include the servo library

int potPosition;   //this variable will store the position of the potentiometer
int servoPosition; //the servo will move to this position

Servo myservo; //create a servo object

void setup()
{

  myservo.attach(9); //tell the servo object that its servo is plugged into pin 9
}

void loop()
{

  potPosition = analogRead(A0); //use analog read to measure the position of the potentiometer (0-1023)

  servoPosition = map(potPosition, 1023, 0, 10, 175); //convert the potentiometer number to a servo position from 20-160
                                                      //Note: its best to avoid driving the little SIK servos all the
                                                      //way to 0 or 180 degrees it can cause the motor to jitter, which is bad for the servo.

  myservo.write(servoPosition); //move the servo to the 10 degree position
}