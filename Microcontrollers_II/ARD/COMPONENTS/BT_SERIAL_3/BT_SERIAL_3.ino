// PROGRAMA PARA LEER LOS DATOS DESDE EL SERIAL 3 DE UN ARDUINO MEGA //

void setup() {
  // Inicializa el puerto serial para la comunicación con el monitor serial
  Serial.begin(9600);
  
  // Inicializa el puerto serial 3 para la comunicación con el módulo Bluetooth
  Serial3.begin(9600);
}

void loop() {
  // Verifica si hay datos disponibles en el puerto serial 3
  if (Serial3.available() > 0) {
    // Lee los datos del puerto serial 3
    char data = Serial3.read();
    
    // Imprime los datos en el monitor serial
    Serial.print(data);
  }
}
