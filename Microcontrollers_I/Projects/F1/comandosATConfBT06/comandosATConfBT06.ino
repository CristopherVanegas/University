// Bluetooth Configuration HC-06 (4 conection) //

#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3);  // RX, TX

void setup() {
  Serial.begin(9600);     // Inicializa la comunicación serie con la computadora
  bluetooth.begin(9600);  // Inicializa la comunicación serie con el módulo HC-06
  delay(1000);            // Espera un segundo para asegurarte de que el módulo esté listo
}

void loop() {
  // Envía comandos AT para configurar el módulo HC-06
  bluetooth.println("AT+NAME=F1.0");      // Configura el nombre del dispositivo
  delay(1000);                            // Espera un segundo
  bluetooth.println("AT+PSWD=1234");      // Configura el código PIN de emparejamiento
  delay(1000);                            // Espera un segundo
  bluetooth.println("AT+UART=9600,0,0");  // Configura la velocidad de comunicación UART
  delay(1000);                            // Espera un segundo

  // Reinicia el módulo HC-06 para aplicar la configuración
  bluetooth.println("AT+RESET");
  delay(1000);  // Espera un segundo para el reinicio

  // El programa finaliza después de configurar el módulo
  while (1) {
    // Muestra la confirmación de la configuración en el monitor serie
    while (bluetooth.available()) {
      char c = bluetooth.read();
      Serial.print(c);
    }
  }
}
