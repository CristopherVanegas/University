void scan() {
  for (int i = 0; i <= 180; i++) {
      servo_1.write(i);

      if (hc_sr04_1() > 101 && i < 90) {
        // rotate to left //
        rotateLeft(100);
        break;
      } else if (hc_sr04_1() > 101 && i < 91) {
        // rotate to right //
        rotateRight(100);
        break;
      }
      delay(25);
  }
  servo_1.write(90);
}