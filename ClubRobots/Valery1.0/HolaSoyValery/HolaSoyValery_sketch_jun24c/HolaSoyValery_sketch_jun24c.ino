#include <SD.h>
#include <TMRpcm.h>

// Configura los pines
const int chipSelect = 53;  // Pin para la selección de la tarjeta SD
const int speakerPin = 11;   // Pin conectado al altavoz o speaker

TMRpcm audio;               // Crea una instancia del objeto TMRpcm

void setup() {
  Serial.begin(9600);
  // Inicializa la comunicación con la tarjeta SD
  if(SD.begin(chipSelect)) Serial.println("Correct");
  else Serial.println("Not correct");

  // Configura el pin del altavoz
  audio.speakerPin = speakerPin;

  // Configura el volumen (0 a 7)
  audio.setVolume(6);
}

void loop() {
  // Reproduce el archivo de sonido "archivo.wav" desde la tarjeta SD
  audio.play("HolaSoyValery.wav");

  // Espera a que se complete la reproducción
  while (audio.isPlaying()) {
    // Puedes realizar otras tareas mientras se reproduce el sonido
  }

  // Repite la reproducción después de un breve tiempo de espera
  delay(1000);
}
