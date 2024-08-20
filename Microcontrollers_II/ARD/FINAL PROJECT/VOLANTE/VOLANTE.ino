#include <Servo.h>
Servo sDir;

void setup() {
  sDir.attach(30);
}

void loop() {
  sDir.write(0);
  delay(2500);
  sDir.write(90);
  delay(2500);
}
