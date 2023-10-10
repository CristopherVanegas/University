#include <AFMotor.h>
#include <Servo.h>

Servo servo_1;

void hc_sr04_1_conf();
int hc_sr04_1();
void hc_sr04_2_conf();
int hc_sr04_2();

void motor_conf();
void fordward_backward();
void forward(int s);
void backward(int s);
void rotateLeft(int s);
void rotateRight(int s);
void stop();
void scan();

void intermitent_led();


void setup() {
  hc_sr04_1_conf();
  hc_sr04_2_conf();
  motor_conf();
  servo_1_conf();
  for (int i = 11; i < 14; i++) pinMode(i, OUTPUT);
}

void loop() {
  Serial.println(hc_sr04_1());
  intermitent_led();

  // if (hc_sr04_1() < 100) {
  //   stop();
  //   scan();
  // } else if (hc_sr04_1() < 10) {
  //   backward(200);
  // } else forward(200);

  // delay(100);
  fordward_backward();
}
