
const int trig_hc_sr04_2 = 22, echo_hc_sr04_2 = 23;
float distancia_hc_sr04_2, tiempo_hc_sr04_2;

void hc_sr04_2_conf() {  
  Serial.begin(9600);
  pinMode(trig_hc_sr04_2, OUTPUT);
  pinMode(trig_hc_sr04_2, INPUT);

}

int hc_sr04_2() {
  digitalWrite(trig_hc_sr04_2, 0);
  delayMicroseconds(10);
  digitalWrite(trig_hc_sr04_2, 1);
  
  // e = v*t ---- v = 343m/s = 0,0343; t = t/2;
  tiempo_hc_sr04_2 = pulseIn(echo_hc_sr04_2, HIGH);  
  distancia_hc_sr04_2 = 0.0343 * (tiempo_hc_sr04_2/2);   // e = v*t ---- v = 343m/s = 0,0343; t = t/2;

  return int(distancia_hc_sr04_2);
}

