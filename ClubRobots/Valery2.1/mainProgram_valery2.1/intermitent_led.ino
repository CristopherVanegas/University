int led = 27;

void intermitend_led_conf() {
  pinMode(led, OUTPUT);         // set as output
  digitalWrite(led, LOW);       // send low signal
}

void intermitent_led() {
  digitalWrite(led, !digitalRead(led));
  delay(250);
}