#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


void setup() {
  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
}

void loop() {
  int t = 2000;
  go_forward();
  delay(t);
  
  go_stop();
  delay(t);

  go_backward();
  delay(t);
  
  go_stop();
  delay(t);
}

void go_forward() {
  motor1.run(FORWARD);
  motor3.run(BACKWARD);
  motor2.run(FORWARD);
  motor4.run(BACKWARD);
}

void go_backward() {
  motor1.run(BACKWARD);
  motor3.run(FORWARD);
  motor2.run(BACKWARD);
  motor4.run(FORWARD);
}

void go_stop() {
  motor1.run(RELEASE);
  motor3.run(RELEASE);
  motor2.run(RELEASE);
  motor4.run(RELEASE);
}
