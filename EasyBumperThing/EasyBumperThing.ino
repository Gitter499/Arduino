#include <RedBot.h>
#include "notes.h"

RedBotMotors motors;

RedBotBumper lBumper = RedBotBumper(3);
RedBotBumper rBumper = RedBotBumper(11);
RedBotEncoder encoder = RedBotEncoder(A2, 10);

RedBotSensor IRSensor1 = RedBotSensor(A3);
RedBotSensor IRSensor2 = RedBotSensor(A6);
RedBotSensor IRSensor3 = RedBotSensor(A7);
const int threshold = 900;
const int power = 150;
const int buzzerPin = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{

  motors.drive(power);

  if (IRSensor1.read() > threshold || IRSensor2.read() > threshold || IRSensor3.read() > threshold)
  {
    reverse();
    delay(500);
    turn();
  }
  auto rBumperState = rBumper.read();

  auto lBumperState = lBumper.read();

  if (rBumperState == LOW || lBumperState == LOW)
  {
    motors.brake();
    playTune();
    delay(10000);
    
  }
}

void reverse()
{
  motors.drive(-power);
  delay(500);
  motors.brake();
  delay(100);
}

void turn()
{
  motors.leftDrive(-120);
  motors.rightDrive(120);
  delay(500);
  motors.brake();
  delay(100);
}

void playTune()
{
  playNote(noteC4, QN);
  playNote(noteC4, QN);

  playNote(noteC4, QN);
  playNote(noteC4, QN);

  playNote(noteC4, QN);
  playNote(noteC4, QN);

  playNote(noteC4, QN);
  playNote(noteC4, QN);

  playNote(noteC4, QN);
  playNote(noteC4, QN);
}

void playNote(int note, int duration)
// This custom function takes two parameters, note and duration to make playing songs easier.
// Each of the notes have been #defined in the notes.h file. The notes are broken down by
// octave and sharp (s) / flat (b).
{
  tone(buzzerPin, note, duration);
  delay(duration);
}