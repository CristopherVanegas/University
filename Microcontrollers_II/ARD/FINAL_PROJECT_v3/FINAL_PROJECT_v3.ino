#include <Servo.h>
#include <Stepper.h>
#include <SD.h>

// Pines para la tarjeta SD
const int chipSelect = 53;

// Número de pasos por revolución del motor paso a paso
const int stepsPerRevolution = 200;

// Declara los servomotores
Servo servo1;
Servo servo2;

// Declara los motores paso a paso
Stepper stepper1(stepsPerRevolution, 22, 24, 23, 25);
Stepper stepper2(stepsPerRevolution, 26, 28, 27, 29);

// Variables para almacenar las posiciones actuales de los servomotores
int pos1 = 90; // Posición inicial del servomotor 1 (90 grados)
int pos2 = 90; // Posición inicial del servomotor 2 (90 grados)

// Pines donde están conectados los servomotores
const int servoPin1 = 32;
const int servoPin2 = 31;

// Incremento de movimiento de los servomotores
const int moveIncrement = 40;

// Incremento de movimiento de los motores paso a paso
const int stepIncrement = 50;

// Variables para almacenar las posiciones de los motores paso a paso
int stepperPos1 = 0;
int stepperPos2 = 0;

// Pin del LED
const int ledPin = 45;
bool ledState = false; // Estado inicial del LED (apagado)

void setup() {
  // Inicializa el monitor serial
  Serial.begin(9600);
  
  // Inicializa el puerto serial 3 para la comunicación con el módulo Bluetooth
  Serial3.begin(9600);
  
  // Adjunta los servomotores a los pines correspondientes
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  
  // Inicializa los servomotores en las posiciones iniciales
  servo1.write(pos1);
  servo2.write(pos2);
  
  // Define la velocidad de los motores paso a paso
  stepper1.setSpeed(60); // Velocidad en RPM
  stepper2.setSpeed(60); // Velocidad en RPM
  
  // Inicializa la tarjeta SD
  if (!SD.begin(chipSelect)) {
    Serial.println("Error al inicializar la tarjeta SD");
    return;
  }
  
  // Lee las posiciones guardadas si existen y mueve los motores en dirección contraria
  if (SD.exists("coordSM1.txt")) {
    File file1 = SD.open("coordSM1.txt");
    if (file1) {
      stepperPos1 = file1.parseInt();
      stepper1.step(-stepperPos1);
      file1.close();
    }
  }
  
  if (SD.exists("coordSM2.txt")) {
    File file2 = SD.open("coordSM2.txt");
    if (file2) {
      stepperPos2 = file2.parseInt();
      stepper2.step(-stepperPos2);
      file2.close();
    }
  }
  
  // Configura el pin del LED como salida
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  // Verifica si hay datos disponibles en el puerto serial 3
  if (Serial3.available() > 0) {
    // Lee los datos del puerto serial 3
    char data = Serial3.read();
    
    // Imprime los datos en el monitor serial
    Serial.print("Recibido: ");
    Serial.println(data);
    
    // Controla los servomotores según los datos recibidos
    switch (data) {
      case '1':
        // Incrementa la posición del servomotor 1 en moveIncrement grados
        if (pos1 <= 180 - moveIncrement) {
          pos1 += moveIncrement;
          servo1.write(pos1);
        }
        break;
      case '2':
        // Decrementa la posición del servomotor 1 en moveIncrement grados
        if (pos1 >= moveIncrement) {
          pos1 -= moveIncrement;
          servo1.write(pos1);
        }
        break;
      case '3':
        // Incrementa la posición del servomotor 2 en moveIncrement grados
        if (pos2 <= 180 - moveIncrement) {
          pos2 += moveIncrement;
          servo2.write(pos2);
        }
        break;
      case '4':
        // Decrementa la posición del servomotor 2 en moveIncrement grados
        if (pos2 >= moveIncrement) {
          pos2 -= moveIncrement;
          servo2.write(pos2);
        }
        break;
      case 'A':
        // Mueve el motor paso a paso 1 a la derecha en stepIncrement pasos
        stepper1.step(stepIncrement);
        stepperPos1 += stepIncrement;
        saveStepperPosition("coordSM1.txt", stepperPos1);
        break;
      case 'B':
        // Mueve el motor paso a paso 1 a la izquierda en stepIncrement pasos
        stepper1.step(-stepIncrement);
        stepperPos1 -= stepIncrement;
        saveStepperPosition("coordSM1.txt", stepperPos1);
        break;
      case 'C':
        // Mueve el motor paso a paso 2 a la derecha en stepIncrement pasos
        stepper2.step(stepIncrement);
        stepperPos2 += stepIncrement;
        saveStepperPosition("coordSM2.txt", stepperPos2);
        break;
      case 'D':
        // Mueve el motor paso a paso 2 a la izquierda en stepIncrement pasos
        stepper2.step(-stepIncrement);
        stepperPos2 -= stepIncrement;
        saveStepperPosition("coordSM2.txt", stepperPos2);
        break;
      case 'O':
        // Cambia el estado del LED
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
        break;
    }
  }
}

void saveStepperPosition(const char* filename, int position) {
  // Abre el archivo para escribir
  File file = SD.open(filename, FILE_WRITE);
  if (file) {
    file.seek(0); // Posiciona el puntero al principio del archivo
    file.print(position);
    file.close();
  } else {
    Serial.print("Error al abrir ");
    Serial.println(filename);
  }
}
