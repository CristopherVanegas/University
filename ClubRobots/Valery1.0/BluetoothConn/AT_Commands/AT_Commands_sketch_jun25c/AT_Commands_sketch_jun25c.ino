#include <SoftwareSerial.h>

#define TR 2
#define RC 13

SoftwareSerial blue(2, 13); // TX -> 10 & RX -> 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  blue.flush();
  blue.begin(9600);

  Serial.println("Listo");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (blue.available() > 0) {
    int estado = blue.read();
    Serial.write(estado);
    // Serial.print("\r");
  }

  if (Serial.available() > 0) {
     blue.write(Serial.read()); 
   }
}
