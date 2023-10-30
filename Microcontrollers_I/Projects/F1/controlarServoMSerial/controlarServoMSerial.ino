// Calibrar direccionales //

#include <Servo.h>

Servo myservo;  // Crea un objeto de tipo Servo

void setup() {
  Serial.begin(9600);
  myservo.attach(10);  // Adjunta el servo al pin 9
  Serial.println("Calibración del Servo. Envia valores de 0 a 180.");
  Serial.println("Escribe 's' para centrar el servo.");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    if (command == 's' || command == 'S') {
      // Centra el servo a 90 grados
      myservo.write(90);
      Serial.println("Servo centrado a 90 grados");
    }
    else if (command >= '0' && command <= '9') {
      // Mueve el servo según el valor proporcionado
      int angle = map(command - '0', 0, 9, 0, 180);  // Convierte el valor numérico a un ángulo entre 0 y 180
      myservo.write(angle);
      Serial.print("Servo movido a ");
      Serial.print(angle);
      Serial.println(" grados");
    }
  }
}
