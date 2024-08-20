#include <Servo.h>
Servo sCodo;
Servo sRotarHand;

int xPin = A0, xVal = 90;
int yPin = A1, yVal = 90;
int buttonPin = 7, buttonVal = 0;
int dt = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  Serial.begin(9600);

  sCodo.attach(30);
  sRotarHand.attach(31);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal = digitalRead(buttonPin);
  if (xVal > 180) xVal = 180;
  else if (xVal < 0) xVal = 0;
  if (yVal > 180) yVal = 180;
  else if (yVal < 0) yVal = 0;
  
  xVal = map(analogRead(xPin), 0, 1023, 0, 180);
  sCodo.write(xVal);
  yVal = map(analogRead(yPin), 0, 1023, 0, 180);
  sRotarHand.write(yVal);
  
  Serial.print("Valor X = ");
  Serial.print(xVal);
  Serial.print(" - Valor Y = ");
  Serial.print(yVal);
  Serial.print(" - Valor Botón = ");
  Serial.println(buttonVal);
  // delay(dt);
}