int led = 27;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, !digitalRead(led));
  delay(250);
}
