
const int trig_hc_sr04_1 = 25, echo_hc_sr04_1 = 24;
float distancia_hc_sr04_1, tiempo_hc_sr04_1;

void hc_sr04_1_conf() {  
  Serial.begin(9600);
  pinMode(trig_hc_sr04_1, OUTPUT);
  pinMode(echo_hc_sr04_1, INPUT);

}

int hc_sr04_1() {
  digitalWrite(trig_hc_sr04_1, 0);
  delayMicroseconds(10);
  digitalWrite(trig_hc_sr04_1, 1);
  
  tiempo_hc_sr04_1 = pulseIn(echo_hc_sr04_1, HIGH);  
  distancia_hc_sr04_1 = 0.0343 * (tiempo_hc_sr04_1/2);   // e = v*t ---- v = 343m/s = 0,0343; t = t/2;

  return int(distancia_hc_sr04_1);
}

