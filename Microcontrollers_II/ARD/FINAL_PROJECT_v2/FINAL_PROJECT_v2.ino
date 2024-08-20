#include <Servo.h>
#include <Stepper.h>

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
        break;
      case 'B':
        // Mueve el motor paso a paso 1 a la izquierda en stepIncrement pasos
        stepper1.step(-stepIncrement);
        break;
      case 'C':
        // Mueve el motor paso a paso 2 a la derecha en stepIncrement pasos
        stepper2.step(stepIncrement);
        break;
      case 'D':
        // Mueve el motor paso a paso 2 a la izquierda en stepIncrement pasos
        stepper2.step(-stepIncrement);
        break;
    }
  }
}
