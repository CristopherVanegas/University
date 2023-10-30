// Programa para calibrar las direccionales del F1 //
// Centro = Servo a 130 grados
// Izquierda = Servo a 100 grados
// Derecha = Servo a 160

#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(10);
  myservo.write(130);
  Serial.begin(9600);
}

String charFromSerial() {
  if (Serial.available() > 0) return Serial.readString();  // Leer una cadena completa
}

void escribirAngulo() {
  int angle = charFromSerial().toInt();  // Convertir la cadena a un número entero

  myservo.write(angle);
  Serial.print("Servo movido a ");
  Serial.print(angle);
  Serial.println(" grados");
}

void controller() {
  if (Serial.available() > 0) {
    switch (Serial.read()) {
      case 'I':
        {
          myservo.write(100);
        }
        break;

      case 'C':
        {
          myservo.write(130);
        }
        break;

      case 'D':
        {
          myservo.write(160);
        }
        break;
    }
  }
}

void loop() {
  controller();
}
