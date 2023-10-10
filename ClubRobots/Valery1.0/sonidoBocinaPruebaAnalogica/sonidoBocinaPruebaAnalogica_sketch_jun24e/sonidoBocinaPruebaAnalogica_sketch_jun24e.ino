const int speakerPin = 9;  // Pin conectado al parlante
int intensity = 0;        // Intensidad del sonido

void setup() {
  pinMode(speakerPin, OUTPUT);  // Configura el pin del parlante como salida
}

void loop() {
  // Genera un pequeño ruido con una intensidad variable
  analogWrite(speakerPin, intensity);

  // Incrementa la intensidad en cada iteración
  intensity = (intensity + 1) % 256;

  // Pequeña pausa para apreciar los cambios en la intensidad
  delay(10);
}
