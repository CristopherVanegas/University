#include <AFMotor.h>
// #include <SoftwareSerial.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// #define TX 9
// #define RX 10

// SoftwareSerial bluetooth(10, 11);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  
	motor4.run(RELEASE);
  motor3.run(RELEASE);
  motor2.run(RELEASE);
  motor1.run(RELEASE);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  if(Serial.available() > 0){
    char data = bluetooth.read();
    data = Serial.read();

    Stop();
    switch (data) {
      case 1:
      {
          uint8_t i;

          // Turn on motor
          motor4.run(FORWARD);
          motor3.run(BACKWARD);
          motor2.run(BACKWARD);
          motor1.run(FORWARD);
          
          // Accelerate from zero to maximum speed
          for (i=0; i<255; i++) 
          {
            motor4.setSpeed(i);  
            motor3.setSpeed(i);  
            motor2.setSpeed(i);  
            motor1.setSpeed(i);  

            delay(10);
          }
          
          // Decelerate from maximum speed to zero
          for (i=255; i!=0; i--) 
          {
            motor4.setSpeed(i);  
            motor3.setSpeed(i);  
            motor2.setSpeed(i);  
            motor1.setSpeed(i);
            
            delay(10);
          }

          // Now change motor direction
          motor4.run(BACKWARD);
          motor3.run(FORWARD);
          motor2.run(FORWARD);
          motor1.run(BACKWARD);
          
          // Accelerate from zero to maximum speed
          for (i=0; i<255; i++) 
          {
            motor4.setSpeed(i);  
            motor3.setSpeed(i);  
            motor2.setSpeed(i);  
            motor1.setSpeed(i);
            delay(10);
          }

          // Decelerate from maximum speed to zero
          for (i=255; i!=0; i--) 
          {
            motor4.setSpeed(i);  
            motor3.setSpeed(i);  
            motor2.setSpeed(i);  
            motor1.setSpeed(i);

            delay(10);
          }

          // Now turn off motor
          motor4.setSpeed(i);  
          motor3.setSpeed(i);  
          motor2.setSpeed(i);  
          motor1.setSpeed(i);

          delay(1000);
      }
        // Mover hacia adelante
        // moveForward();
        break;
      case 2:
        // Mover hacia atrás
        moveBackward();
        break;
      case 3:
        // Girar hacia la derecha
        turnRight();
        break;
      case 4:
        // Girar hacia la izquierda
        turnLeft();
        break;
      case 'b':
        // Enciende FOCOS
        // digitalWrite(13, HIGH);
        break;
      case 'l':
        // Enciende Buzzer
        digitalWrite(13, !digitalRead(13));
        break;
    }
    delay(25);
  }
}

void moveForward() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}


void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}