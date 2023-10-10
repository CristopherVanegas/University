static void servo_1_conf() {
  servo_1.attach(10);
}

void servo_1_mov() {
  servo_1.write(0);
  delay(1000);

  servo_1.write(180);
  delay(1000);
}
