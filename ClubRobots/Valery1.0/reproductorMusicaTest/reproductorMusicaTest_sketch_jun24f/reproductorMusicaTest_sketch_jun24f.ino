#include <SD.h>
#include <TMRpcm.h>

const int chipSelect = 53;      // Pin para la selección de la tarjeta SD
const int speakerPin = 9;      // Pin conectado a la bocina

TMRpcm audio;                   // Crea una instancia del objeto TMRpcm

void setup() {
  Serial.begin(9600);           // Inicia la comunicación serial
  audio.speakerPin = speakerPin; // Configura el pin de la bocina

  if (!SD.begin(chipSelect)) {
    Serial.println("Error al inicializar la tarjeta SD");
    delay(5000);
    return;
  }
  else {
    Serial.println("Tarjeta SD inicializada");

    // Reproduce el archivo de audio
    audio.play("vegeta.wav");
    while (audio.isPlaying()) {
      // Espera a que termine la reproducción del audio
    }
    
    Serial.println("Reproducción de audio completada.");

    // Abre el archivo de texto
    File archivo = SD.open("Test1.txt");
    if (archivo) {
      // Lee y muestra el contenido del archivo de texto
      while (archivo.available()) {
        char caracter = archivo.read();
        Serial.print(caracter);
      }
      archivo.close();
    } else {
      Serial.println("Error al abrir el archivo de texto");
    }
  }
}

void loop() {
  // // Tu código principal, si lo tienes, puede ir aquí
  // audio.play("HolaSoyValery.wav");
  // while (audio.isPlaying()) {
  //   // Espera a que termine la reproducción del audio
  // }
  // Serial.println("Reproducción de audio completada.");

  
  if (!SD.begin(chipSelect)) {
    Serial.println("Error al inicializar la tarjeta SD");
    delay(2000);
    return;
  }
  else {
    Serial.println("Tarjeta SD inicializada");

    // Reproduce el archivo de audio
    audio.play("vegeta.wav");
    while (audio.isPlaying()) {
      // Espera a que termine la reproducción del audio
    }
    
    Serial.println("Reproducción de audio completada.");

    // Abre el archivo de texto
    File archivo = SD.open("Test1.txt");
    if (archivo) {
      // Lee y muestra el contenido del archivo de texto
      while (archivo.available()) {
        char caracter = archivo.read();
        Serial.print(caracter);
      }
      archivo.close();
    } else {
      Serial.println("Error al abrir el archivo de texto");
    }
  }

  delay(3000);
}
