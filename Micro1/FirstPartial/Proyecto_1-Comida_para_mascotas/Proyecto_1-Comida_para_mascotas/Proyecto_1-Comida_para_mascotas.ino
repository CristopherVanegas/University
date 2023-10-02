#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección I2C del módulo LCD
#define I2C_ADDR 0x27

// Tamaño de la pantalla LCD (16 columnas x 2 filas)
#define LCD_COLUMNS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS);


#include <Keypad.h>
#include <Servo.h>
Servo servo1;

const byte filas = 4, columnas = 4;
byte pinesFilas[] = { 9, 8, 7, 6 }, pinesColumnas[] = { 5, 4, 3, 2 };
char teclas[4][4] = { { '1', '2', '3', 'A' }, { '4', '5', '6', 'B' }, { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' } };

Keypad teclado1 = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);

const int SENSOR_PRESS = A0;
int PIR_SENSOR = A3;
const int TRIG = A1, ECHO = A2;
float distancia, tiempo;

int red = 11, blue = 12, green = 13;
int map_datos_press;

int mode;

void setup() {
  for (int i = 11; i <= 13; i++) pinMode(i, OUTPUT);
  for (int i = 0; i <= 13; i++) digitalWrite(i, 0);
  Serial.begin(9600);
  Serial.println("Listo!");
  pinMode(SENSOR_PRESS, INPUT);
  pinMode(PIR_SENSOR, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  servo1.attach(10);

  lcd_conf();
}

void lcd_conf() {
  // Inicializa la comunicación I2C
  Wire.begin();

  // Inicializa la pantalla LCD
  lcd.init();

  // Enciende el retroiluminación (ajusta según sea necesario)
  lcd.backlight();
  lcd.clear();

  // Muestra el mensaje en la pantalla
  lcd.setCursor(3, 0);      // Establece la posición del cursor
  lcd.print("Bienvenido");  // Mensaje a mostrar
}

void loop() {
  mainProgram();
  // keypad();
}

void mainProgram() {
  switch (mode) {
    case 1:{automatica();} break;
    case 2:{manual();} break; 
  }

  interface();

  if (comprobarPIR() == 1) {
    mServo();
  }
}

void automatica() {
  return 0;
}

void manual() {
  return 0;
}

void interface() {
  
  lcd.setCursor(3, 0);  // Establece la posición del cursor
  lcd.print("Bienvenido");
  lcd.setCursor(0, 1);  // Establece la posición del cursor
  lcd.print(" > * to Config");

  char c1 = keypad();

  while (c1 == '*') {
    lcd.clear();
    lcd.setCursor(6, 0);  // Establece la posición del cursor
    lcd.print("Modo");
    lcd.setCursor(0, 1);  // Establece la posición del cursor
    lcd.print("1. Auto   2.Man");

    char c2 = keypad();

    if (c2 == '1') {
      mode = 1;
      lcd.clear();
      lcd.setCursor(0, 0);  // Establece la posición del cursor
      lcd.print("Ingrese cada cuantas");
      lcd.setCursor(0, 1);  // Establece la posición del cursor
      lcd.print("horas: ");

      delay(5000);
      break;
    }

    if (c2 == '2') {
      mode = 2;
      lcd.clear();
      lcd.setCursor(6, 0);  // Establece la posición del cursor
      lcd.print("Done");

      delay(5000);
      break;
    }

    delay(500);
    lcd.clear();
  }

  delay(500);
}

char keypad() {
  char tecla_presionada = teclado1.getKey();                                        //Verifica si alguna tecla fue presionada
  if (tecla_presionada) Serial.print("Tecla: " + String(tecla_presionada) + "\n");  //Monitor Serial

  return tecla_presionada;
}

void mServo() {
  int d = 1500;
  Serial.println("Servo a 0 grados");
  servo1.write(0);
  delay(d);
  Serial.println("Servo a 180 grados");
  servo1.write(180);
  delay(d);
}

int press() {
  Serial.println(analogRead(SENSOR_PRESS));
  map_datos_press = map(analogRead(SENSOR_PRESS), 0, 1023, 0, 255);
  analogWrite(red, map_datos_press);

  return map_datos_press;
}

void pwm() {
  for (int i = 0; i < 255; i++) {
    analogWrite(red, i);
    delay(10);
  }
}

int comprobarPIR() {
  if (digitalRead(PIR_SENSOR) == 1) digitalWrite(blue, 1);
  else digitalWrite(blue, 0);

  return digitalRead(PIR_SENSOR);
}

void hcsr04() {
  digitalWrite(TRIG, 0);
  delayMicroseconds(10);
  digitalWrite(TRIG, 1);

  tiempo = pulseIn(ECHO, HIGH);
  distancia = 0.0343 * (tiempo / 2);  // e = v*t ---- v = 343m/s = 0,0343; t = t/2;
  Serial.println(distancia);
}
