#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Dirección I2C del LCD

// LEDs de los peatones
int vp = 4;   // led verde peatones
int ap = 7;   // led amarillo peatones
int rp = 10;  // led rojo peatones

// LEDs de los carros
int vc = A2;  // led verde carros
int ac = A1;  // led amarillo carros
int rc = A0;  // led rojo carros

int pushbutton = 2;
bool senal = 0;

// Variables para gestionar el tiempo
unsigned long previousMillis = 0;
const long verdeInterval = 2000;     // 2 segundos
const long amarilloInterval = 1000;  // 1 segundo

// Enumeraciones para los estados de los semáforos
enum SemaforoState { VERDE_P,
                     AMARILLO_P,
                     ROJO_P,
                     VERDE_C,
                     AMARILLO_C,
                     ROJO_C };
volatile SemaforoState currentSemaforoState = VERDE_P;

// Función para actualizar el estado del semáforo
void actualizarSemaforo() {
  unsigned long currentMillis = millis();

  switch (currentSemaforoState) {
    case VERDE_P:
      if (currentMillis - previousMillis >= verdeInterval) {
        previousMillis = currentMillis;
        digitalWrite(vp, LOW);
        digitalWrite(ap, HIGH);
        currentSemaforoState = AMARILLO_P;
      } else {
        digitalWrite(vp, HIGH);
        digitalWrite(ap, LOW);
        digitalWrite(rp, LOW);
        digitalWrite(vc, LOW);
        digitalWrite(ac, LOW);
        digitalWrite(rc, HIGH);
        lcd.setCursor(0, 0);
        lcd.print("Peaton: Verde   ");
        lcd.setCursor(0, 1);
        lcd.print("Carros: Rojo    ");
      }
      break;

    case AMARILLO_P:
      if (currentMillis - previousMillis >= amarilloInterval) {
        previousMillis = currentMillis;
        digitalWrite(ap, LOW);
        digitalWrite(rp, HIGH);
        currentSemaforoState = VERDE_C;
      } else {
        digitalWrite(vp, LOW);
        digitalWrite(ap, HIGH);
        digitalWrite(rp, LOW);
        digitalWrite(vc, LOW);
        digitalWrite(ac, LOW);
        digitalWrite(rc, HIGH);
        lcd.setCursor(0, 0);
        lcd.print("Peaton: Amarillo");
        lcd.setCursor(0, 1);
        lcd.print("Carros: Rojo    ");
      }
      break;

    case VERDE_C:
      if (currentMillis - previousMillis >= verdeInterval) {
        previousMillis = currentMillis;
        digitalWrite(vc, LOW);
        digitalWrite(ac, HIGH);
        currentSemaforoState = AMARILLO_C;
      } else {
        digitalWrite(vp, LOW);
        digitalWrite(ap, LOW);
        digitalWrite(rp, HIGH);
        digitalWrite(vc, HIGH);
        digitalWrite(ac, LOW);
        digitalWrite(rc, LOW);
        lcd.setCursor(0, 0);
        lcd.print("Peaton: Rojo    ");
        lcd.setCursor(0, 1);
        lcd.print("Carros: Verde   ");
      }
      break;

    case AMARILLO_C:
      if (currentMillis - previousMillis >= amarilloInterval) {
        previousMillis = currentMillis;
        digitalWrite(ac, LOW);
        digitalWrite(rc, HIGH);
        currentSemaforoState = VERDE_P;
      } else {
        digitalWrite(vp, LOW);
        digitalWrite(ap, LOW);
        digitalWrite(rp, HIGH);
        digitalWrite(vc, LOW);
        digitalWrite(ac, HIGH);
        digitalWrite(rc, LOW);
        lcd.setCursor(0, 0);
        lcd.print("Peaton: Rojo    ");
        lcd.setCursor(0, 1);
        lcd.print("Carros: Amarillo");
      }
      break;
  }
}

// Función de la interrupción
void reiniciarSecuencia() {
  currentSemaforoState = VERDE_P;
  previousMillis = millis();
}

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(vp, OUTPUT);
  pinMode(ap, OUTPUT);
  pinMode(rp, OUTPUT);

  pinMode(vc, OUTPUT);
  pinMode(ac, OUTPUT);
  pinMode(rc, OUTPUT);

  pinMode(pushbutton, INPUT);
  attachInterrupt(digitalPinToInterrupt(pushbutton), reiniciarSecuencia, RISING);
}

void loop() {
  actualizarSemaforo();

  if (digitalRead(pushbutton)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pase Peaton");
    lcd.setCursor(0, 1);
    lcd.print("Sem Peaton Act");
    delay(500);
  }
}
