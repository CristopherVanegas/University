#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

Servo myservo;

const int passwd[4] = {'1', '2', '3', '4'};

const byte filas = 4, columnas = 4;
byte pinesFilas[] = { 9, 8, 7, 6 }, pinesColumnas[] = { 5, 4, 3, 2 };
char teclas[4][4] = { { '1', '2', '3', 'A' }, { '4', '5', '6', 'B' }, { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' } };

LiquidCrystal_I2C lcd(32, 16, 2);  // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2)
Keypad teclado1 = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);

void setup() {
  Serial.begin(9600);
  setup_1603A();

  myservo.attach(10);
  Serial.println("Teclado 4x4 \n");
}

void loop() {
  //Verifica si alguna tecla fue presionada y la envia como parametro a la funcion de char_to_1602A, si no solo saluda con el mensaje Hello World! [Micro 1]
  // greeting_1602A();
  // char tecla_presionada = teclado1.waitForKey();
  // if (tecla_presionada) char_to_1602A(tecla_presionada);
  // lcd.display();

  lcd.setCursor(0, 0);
  lcd.print("Enter 4 digits");

  askForPasswd();
}

void setup_1603A() {
  lcd.init();
  lcd.backlight();
}

void askForPasswd() {
  myservo.write(0);
  if (verificarPassword()) {
    lcd.setCursor(0, 0);
    lcd.print("[ Access Granted ]");
    myservo.write(90);
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("[ Access Denied ]");
  }

  lcd.display();
}

bool verificarPassword() {
  int c = teclado1.waitForKey();
  for (int i = 0; i < 4; i++) {
    if (c == passwd[i]) { 
      char_to_1602A();
    }
    else return false;
  }

  return true;
}

void greeting_1602A() {
  lcd.setCursor(0, 0);
  lcd.print("[ Hello World! ]");
  lcd.setCursor(0, 1);
  lcd.print(">  Micro 1 ;)  <");
}

void char_to_1602A(char a) {
  Serial.print("Tecla: " + String(a) + "\n");  //Monitor Serial
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("[ Char Pressed ]");
  lcd.setCursor(5, 1);
  lcd.print("[ " + String(a) + " ]");

  delay(700);
}
