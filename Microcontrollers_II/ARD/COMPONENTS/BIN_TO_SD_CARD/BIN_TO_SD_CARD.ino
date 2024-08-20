// Write a binary file in SD Card //
#include <SPI.h>
#include <SD.h>

const int chipSelect = 53; // Pin para seleccionar la tarjeta SD

void setup() {
  // Inicializa la comunicación serial para depuración
  Serial.begin(9600);
  while (!Serial) {
    ; // Espera a que se establezca la conexión serial
  }

  // Configura los pines SPI
  pinMode(50, INPUT);  // MISO
  pinMode(51, OUTPUT); // MOSI
  pinMode(52, OUTPUT); // SCK
  pinMode(53, OUTPUT); // CS

  // Inicializa la tarjeta SD
  if (!SD.begin(chipSelect)) {
    Serial.println("No se pudo inicializar la tarjeta SD.");
    return;
  }
  Serial.println("Tarjeta SD inicializada.");

  // Nombre del archivo a crear/escribir
  const char *filename = "logfile.bin";

  // Abrir el archivo en modo de escritura (append). Si no existe, lo crea.
  File file = SD.open(filename, FILE_WRITE);
  
  if (file) {
    Serial.print("Escribiendo en el archivo: ");
    Serial.println(filename);

    // Mensaje a escribir en el archivo
    String message = "Arduino encendido o reiniciado.\n";
    
    // Convertir el string a una secuencia de bytes
    file.write((const uint8_t*)message.c_str(), message.length());

    // Cerrar el archivo para asegurar que se guarde correctamente
    file.close();
    Serial.println("Escritura completada.");
  } else {
    // Si el archivo no se puede abrir
    Serial.println("No se pudo abrir el archivo.");
  }
}

void loop() {
  // No se requiere nada en el loop para esta funcionalidad
}
