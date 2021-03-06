/***********************************************************************
 * Exp2_DriveForward -- RedBot Experiment 2
 * 
 * Drive forward and stop.
 * 
 * Hardware setup:
 * The Power switch must be on, the motors must be connected, and the board must be receiving power 
 * from the battery. The motor switch must also be switched to RUN.
 *
 * 23 Sept 2013 N. Seidle/M. Hord
 * 04 Oct 2014 B. Huang
 ***********************************************************************/
/***********************************************************************
 * Exp4_1_MakingSounds -- RedBot Experiment 4.1
 *
 * Push the button (D12) to make some noise and start running!
 *
 * Hardware setup:
 * Plug the included RedBot Buzzer board into the Servo header labeled 9.
 *
 * This sketch was written by SparkFun Electronics,with lots of help from 
 * the Arduino community. This code is completely free for any use.
 * 
 * 23 Sept 2013 N. Seidle/M. Hord
 * 29 Oct 2014 B. Huang
 ***********************************************************************/

#include <RedBot.h>
RedBotMotors motors;
RedBotEncoder encoder;

// Create a couple of constants for our pins.
const int buzzerPin = 9;
const int buttonPin = 12;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP); // configures the button as an INPUT
  // INPUT_PULLUP defaults it to HIGH.
  pinMode(buzzerPin, OUTPUT); // configures the buzzerPin as an OUTPUT
}

void loop()
{
  auto ticks_right = encoder.getTicks(RIGHT);
  auto ticks_left = encoder.getTicks(LEFT);

  Serial.println(ticks_left);
  Serial.println(ticks_right);

  if (digitalRead(buttonPin) == LOW) // if the button is pushed (LOW)
  {
    tone(buzzerPin, 1000); // Play a 1kHz tone on the pin number held in
    //  the variable "buzzerPin".
    delay(125);        // Wait for 125ms.
    noTone(buzzerPin); // Stop playing the tone.

    tone(buzzerPin, 2000); // Play a 2kHz tone on the buzzer pin

    motors.drive(255); // Start the motors. The whiskers will stop them.
    delay(1000);       // delay for 1000 ms (1 second)

    noTone(buzzerPin); // Stop playing the tone.
    motors.brake();    // brake() or stop the motors.
  }
  else // otherwise, do this.
  {
  }
}
