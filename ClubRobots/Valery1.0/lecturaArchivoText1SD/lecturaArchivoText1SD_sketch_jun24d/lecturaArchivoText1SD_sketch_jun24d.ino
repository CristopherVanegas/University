#include <SD.h>

// Configura los pines
const int chipSelect = 53;  // Pin para la selección de la tarjeta SD

void setup() {
  Serial.begin(9600);  // Inicia la comunicación serial

  // Inicializa la comunicación con la tarjeta SD
  if (!SD.begin(chipSelect)) {
    Serial.println("Error al inicializar la tarjeta SD");
    return;
  }

  // Abre el archivo de texto
  File archivo = SD.open("Test1.txt");
  
  // Verifica si el archivo se abrió correctamente
  if (archivo) {
    // Lee y muestra el contenido del archivo línea por línea
    while (archivo.available()) {
      String linea = archivo.readStringUntil('\n');
      Serial.println(linea);
    }
    // Cierra el archivo
    archivo.close();
  } else {
    Serial.println("Error al abrir el archivo");
  }
}

void loop() {
  // Tu código principal, si lo tienes, puede ir aquí
}
