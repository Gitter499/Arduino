#include <RedBot.h>

// Constants
// Box

const int threshold = 800;

const int width = 36;  // width in inches
const int length = 36; // length in inches

const int botWidth = 7;      // inches
const float botLength = 7.5; // inches

const float wheelDiam = 2.56;
const float wheelCirc = PI * wheelDiam;

const int buttonPin = 12;
const int countsPerRev = 192;

const int power = 90;

RedBotMotors motors;

enum Sides
{
  L,
  R
};

enum Direction
{
  NORTH,
  SOUTH,
  WEST,
  EAST
};

Direction direction = NORTH; // Defaults to North

void changeDirection(int consumer, Sides side)
{
  if (consumer >= 5)
  {
    consumer = 1;
  }
  else if (consumer <= 0)
  {
    consumer = 4;
  }

  switch (consumer)
  {
  case 1:
    direction = NORTH;
    break;
  case 2:
    if (side == RIGHT)
    {
      direction = EAST;
    }
    else
    {
      direction = WEST;
    }
    break;
  case 3:
    direction = SOUTH;
    break;
  case 4:
    if (side == RIGHT)
    {
      direction = WEST;
    }
    else
    {
      direction = EAST;
    }
    break;
  }
}

RedBotBumper lBumper = RedBotBumper(3);
RedBotBumper rBumper = RedBotBumper(11);
RedBotEncoder encoder = RedBotEncoder(A2, 10);

RedBotSensor IRSensor1 = RedBotSensor(A3); 
RedBotSensor IRSensor2 = RedBotSensor(A6);
RedBotSensor IRSensor3 = RedBotSensor(A7);

int lBumperState;
int rBumperState;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  if (IRSensor1.read() >= threshold || IRSensor2.read() >= threshold || IRSensor3.read() >= threshold) {
    move(-1);
    switch (direction) {
      case NORTH:
        
    }
    
  }

}

// Control functions

void move(float inches)
{
  long lCount = 0;
  long rCount = 0;
  float numRev;

  numRev = (float)inches / wheelCirc;

  encoder.clearEnc(BOTH); // clear the encoder

  motors.drive(power);

  while (rCount < numRev * countsPerRev)
  {
    // while the left encoder is less than the target count -- debug print
    // the encoder values and wait -- this is a holding loop.
    lCount = encoder.getTicks(LEFT);
    rCount = encoder.getTicks(RIGHT);
  }
  motors.brake();
}

int consumer = 0;

void turnLeft(int degrees)
{
  
  // L = 90° / 360° × 𝛑 × d = 0.25 × 3.14 × 6.125 = 4.81 inches

  float arcLength = degrees / 360 * PI * 6.125;

  motors.leftDrive(arcLength);
  motors.rightDrive(-arcLength);
  motors.brake();

  changeDirection(consumer + 1, L);
}

void turnRight(int degrees)
{

  float arcLength = degrees / 360 * PI * 6.125;

  motors.leftDrive(-arcLength);
  motors.rightDrive(arcLength);
  motors.brake();
  changeDirection(consumer + 1, R);
}

