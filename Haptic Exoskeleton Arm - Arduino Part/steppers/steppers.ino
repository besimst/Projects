/* Rotary encoder with attachInterrupt
Counts pulses from an incremental encoder and put the result in variable counter. 
Taking also into account the direction and counts down when the rotor rotates in 
the other direction.
This code is used attachInterrupt 0 and 1 which are pins 2 and 3 moust Arduino.
For more information about attachInterrupt see:
http://arduino.cc/en/Reference/AttachInterrupt
 
created 2014
by Ben-Tommy Eriksen
https://github.com/BenTommyE/BenRotaryEncoder
 
*/

// Encoder connect to digitalpin 2 and 3 on the Arduino.
#include <Stepper.h>
const int stepsPerRevolution = 360/7;
 //This variable will increase or decrease depending on the rotation of encoder
float counter = 0;

Stepper Mystepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  Serial.begin(2400);
  Mystepper.setSpeed(60);
}

void loop() {
  // Send the value of counter
  if(Serial.available()>0)
  {
  counter=Serial.read();
  Mystepper.step(counter*1/7);
  }
}
