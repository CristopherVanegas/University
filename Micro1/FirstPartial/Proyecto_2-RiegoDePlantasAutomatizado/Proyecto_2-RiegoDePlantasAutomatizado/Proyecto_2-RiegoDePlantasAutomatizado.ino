int sensor_humedad_tierra_A0 = A0;
int sensor_humedad_tierra_D0 = A1;

int motor_rele = 3;
bool motor_activator = false;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_humedad_tierra_A0, INPUT);
  pinMode(sensor_humedad_tierra_D0, INPUT);
  pinMode(motor_rele, OUTPUT);
  Serial.println("Listo!");
}

void loop() {
  Serial.println(gnd_humity_a());
  Serial.println(gnd_humity_d());

  if (gnd_humity_a() < 900) digitalWrite(motor_rele, !motor_activator);
  else digitalWrite(motor_rele, motor_activator=false);
  delay(250);
}

int gnd_humity_a() {
  return analogRead(sensor_humedad_tierra_A0);
}

int gnd_humity_d() {
  return digitalRead(sensor_humedad_tierra_D0);
}