#include <SoftwareSerial.h>

// Configuración del puerto serial 3 del Arduino Mega
// TX3 -> Pin 14, RX3 -> Pin 15
#define BT_RX 15
#define BT_TX 14

void setup() {
  // Inicializa la comunicación serial con el ordenador y el HC-05
  Serial.begin(9600);      // Comunicación con el ordenador
  Serial3.begin(9600);     // Comunicación con el HC-05

  // Mensaje de inicio
  Serial.println("Iniciando comunicación con el HC-05...");
}

void loop() {
  // Verifica si hay datos disponibles desde el HC-05
  if (Serial3.available()) {
    char receivedChar = Serial3.read(); // Lee un caracter
    Serial.print("Recibido desde HC-05: ");
    Serial.println(receivedChar);       // Imprime el caracter recibido
  }

  // Verifica si hay datos disponibles desde el ordenador
  if (Serial.available()) {
    char sentChar = Serial.read();  // Lee un caracter
    Serial3.print(sentChar);        // Envía el caracter al HC-05
  }
}
