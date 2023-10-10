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

void loop() 
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