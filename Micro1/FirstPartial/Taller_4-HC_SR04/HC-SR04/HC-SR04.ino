const int trig = 3, echo = 2;
float distancia, tiempo;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  for (int i = 11; i < 14; i++) pinMode(i, OUTPUT);
}

void loop()
{  
  hcsr04();
  leds(); 
  delay(200);
}

void hcsr04() {
  digitalWrite(trig, 0);
  delayMicroseconds(10);
  digitalWrite(trig, 1);
  
  // e = v*t ---- v = 343m/s = 0,0343; t = t/2;
  tiempo = pulseIn(echo, HIGH);  
  distancia = 0.0343 * (tiempo/2); 
  Serial.println(distancia);
}

void leds()
{
  for (int i = 11; i < 14; i++) digitalWrite(i, 0);

  if(distancia < 20) digitalWrite(13, !digitalRead(13));
  else if (distancia < 40) digitalWrite(12, !digitalRead(12));
  else if (distancia > 60) digitalWrite(11, !digitalRead(11));
}
