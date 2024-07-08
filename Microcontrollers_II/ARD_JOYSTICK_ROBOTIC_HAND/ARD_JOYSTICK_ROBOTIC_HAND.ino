/* ROBOTIC HAND JOYSTICK VERSION */
// PROGRAM BY: CRISTOPHER VANEGAS S.
// THIS PROGRAM CONTROLS A HAND WITH 2 SERVOMOTORS AND 2 STEPPER MOTORS.
// DESIGN INITIALLY FOR AN ARDUINO MEGA.
// UPDATE: ADD MOTION BY ATTACHING WHEELS IN ORDER TO CREATE A CRANE.

#include <Stepper.h>
int stepsPerRevolution = 2048;  // revolutions
int motSpeed = 12;              // stepper motor speed

int xPin = A7, xVal = 0;
int yPin = A8, yVal = 0;
int buttonPin = 30;

int dt = 50;  // delay time

Stepper motor1(stepsPerRevolution, 22, 23, 24, 25);
Stepper motor2(stepsPerRevolution, 26, 27, 28, 29);

int dt = 1500;

void setup() {
  Serial.begin(9600);
  // Setup the pinin/out for JOYSTICK
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT);

  // Setup for stepperMotors Speed
  motor1.setSpeed(motSpeed);
  motor2.setSpeed(motSpeed);
}

int getValXMapped() {
  return map(analogRead(xPin), 0, 1023, 0, 180);
}
int getValYMapped() {
  return map(analogRead(yPin), 0, 1023, 0, 180);
}
int getValJYButton() {
  return digitalRead(buttonPin);
}

void valsReadFromJY() {
  Serial.print("Valor X Mapeado de 0 a 180 = ");
  Serial.print(getValXMapped());
  Serial.print(" - Valor Y Mapeado de 0 a 180 = ");
  Serial.print(getValYMapped());
  Serial.print(" - Valor Botón = ");
  Serial.println(getValJYButton());
}

void loop() {
  valsReadFromJY();
  if (getValXMapped() > 90) motor1.step(xVal++);
  else if (getValXMapped() < 90) motor1.step(xVal--);
  
  if (getValYMapped() > 90) motor1.step(yVal++);
  else if (getValYMapped() < 90) motor1.step(yVal--);

  delay(dt);
}

















