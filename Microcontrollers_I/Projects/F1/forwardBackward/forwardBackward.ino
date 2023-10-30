// Forward and Backward Motors //

#include <AFMotor.h>

AF_DCMotor motor4(4);
AF_DCMotor motor3(3);
AF_DCMotor motor2(2);
AF_DCMotor motor1(1);

void setup() 
{
	//Set initial speed of the motor & stop
	motor4.setSpeed(200);
  motor3.setSpeed(200);
	motor2.setSpeed(200);
	motor1.setSpeed(200);

	motor4.run(RELEASE);
  motor3.run(RELEASE);
  motor2.run(RELEASE);
  motor1.run(RELEASE);
}

void loop() {
  forward();
  backward();
}

void forward() {
  // Turn on motor
	motor4.run(FORWARD);
	motor3.run(FORWARD);
	motor2.run(FORWARD);
	motor1.run(FORWARD);

  // Motor Speed to 255
  motor4.setSpeed(255);  
  motor3.setSpeed(255);  
  motor2.setSpeed(255); 
  motor1.setSpeed(255);  

  delay(3000);

  // Turn on motor
	motor4.run(RELEASE);
	motor3.run(RELEASE);
	motor2.run(RELEASE);
	motor1.run(RELEASE);

  delay(2000);
}

void backward() {
  // Turn on motor
	motor4.run(BACKWARD);
	motor3.run(BACKWARD);
	motor2.run(BACKWARD);
	motor1.run(BACKWARD);

  // Motor Speed to 255
  motor4.setSpeed(255);  
  motor3.setSpeed(255);  
  motor2.setSpeed(255); 
  motor1.setSpeed(255);  

  delay(3000);

  // Turn on motor
	motor4.run(RELEASE);
	motor3.run(RELEASE);
	motor2.run(RELEASE);
	motor1.run(RELEASE);

  delay(2000);
}

