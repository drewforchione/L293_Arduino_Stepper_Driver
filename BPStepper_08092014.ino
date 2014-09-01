//Bipolar Stepper Driver
//Design Team 16, University of Akron
//Andrew Forchione
//August 9th, 2014

/* Circuit uses L293D quad half h bridge with bipolar motor config*/

#include <Stepper.h>

int A = 10;
int B = 11;
int C = 12;
int D = 13;

Stepper motor(200, D, B, C, A);  

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  while (!Serial);
  Serial.begin(9600);
  motor.setSpeed(90);
  Serial.println("Please Enter Motor Speed, Number of Turns Separated by a Comma.");
  Serial.println("Max speed is 150. Use a negative number of turns for CW, positive for CCW.");
  Serial.println("Don't overdo it, asshole.");
  Serial.println("Below is an example:");
  Serial.println("90,-200");
}

void loop()
{
  if (Serial.available())
  {
    int speedVal = Serial.parseInt();
    motor.setSpeed(speedVal); 
    int steps = Serial.parseInt();
    motor.step(steps);
  }
}
