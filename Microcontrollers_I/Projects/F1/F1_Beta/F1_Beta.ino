// Programa principal del F1 //
#include <SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h>

Servo myservo;

AF_DCMotor motor4(4);
AF_DCMotor motor3(3);
AF_DCMotor motor2(2);
AF_DCMotor motor1(1);

int leftD = 106, centerD = 126, rightD = 146;     // izquierda, centro, derecha //

void setup() {

  // retro light conf
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);

  int speed = 255;
  // BT conf
  Serial.begin(9600);     // Inicializa la comunicación serie con la computadora
  delay(1000);            // Espera un segundo para asegurarte de que el módulo esté listo
  
  // Servo conf
  myservo.attach(10);
  myservo.write(130);

  //Set initial speed of the motor & stop
	motor4.setSpeed(170);
  motor3.setSpeed(speed);
	motor2.setSpeed(speed);
	motor1.setSpeed(speed);

	motor4.run(RELEASE);
  motor3.run(RELEASE);
  motor2.run(RELEASE);
  motor1.run(RELEASE);
}

void loop() {
  // El programa finaliza después de configurar el módulo
  while (true) {
    // Muestra la confirmación de la configuración en el monitor serie
    while (Serial.available()) {
      char c = Serial.read();
      Serial.print(c);

      switch(c) {
        case '1': {
          center();
        } break;

        case '2': {
          left();
        } break;

        case '3': {
          right();
        } break;

        case '8': {
          forward();
        } break;

        case '9': {
          stop();
        } break;

        case '4': {
          backward();
        } break;
      }
    }
  }
}

void center() {
  myservo.write(centerD);
}

void left() {
  myservo.write(leftD);
}

void right() {
  myservo.write(rightD);
}

void stop() {
  // Turn on motor
	motor4.run(RELEASE);
	motor3.run(RELEASE);
	motor2.run(RELEASE);
	motor1.run(RELEASE);
}

void forward() {
  digitalWrite(13, LOW);
  // Turn on motor
	motor4.run(FORWARD);
	motor3.run(FORWARD);
	motor2.run(FORWARD);
	motor1.run(FORWARD);
}

void backward() {
  digitalWrite(13, HIGH);
  // Turn on motor
	motor4.run(BACKWARD);
	motor3.run(BACKWARD);
	motor2.run(BACKWARD);
	motor1.run(BACKWARD);
}


