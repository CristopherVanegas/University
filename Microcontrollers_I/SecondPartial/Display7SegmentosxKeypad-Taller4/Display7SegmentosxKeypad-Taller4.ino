#include <Keypad.h>

// Definición de pines para el display de 7 segmentos
const int segmentos[8] = {2, 3, 4, 5, 6, 7, 8, 13}; // Pins a g

const byte filas = 4, columnas = 4;
byte pinesFilas[] = { 12, 11, 10, 9 }, pinesColumnas[] = { A4, A3, A2, A1 };
char teclas[4][4] = { { '1', '2', '3', 'A' }, { '4', '5', '6', 'B' }, { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' } };
Keypad teclado1 = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);

void setup() {
  Serial.begin(9600);
  for (int i = 0; i <= 7; i++) pinMode(segmentos[i], OUTPUT);
  Serial.println("Teclado 4x4 \n");

  probarSegs(25);
}

void probarSegs(int t) {
  for (int i = 0; i <= 7; i++) {
    digitalWrite(segmentos[i], 1);
    delay(t);
    digitalWrite(segmentos[i], 0);
    delay(t);
  }
}

void mostrarNumero(char numero) {
  Serial.println(numero);

  switch (numero) {
    case '0':
      // Representación del número 0
      digitalWrite(segmentos[0], 1);
      digitalWrite(segmentos[1], 1);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 1);
      digitalWrite(segmentos[4], 1);
      digitalWrite(segmentos[5], 1);
      digitalWrite(segmentos[6], 0);
      break;
    case '1':
      // Representación del número 1
      digitalWrite(segmentos[0], 0);
      digitalWrite(segmentos[1], 1);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 0);
      digitalWrite(segmentos[4], 0);
      digitalWrite(segmentos[5], 0);
      digitalWrite(segmentos[6], 0);
      break;
    case '2':
      // Representación del número 2
      digitalWrite(segmentos[0], 1);
      digitalWrite(segmentos[1], 1);
      digitalWrite(segmentos[2], 0);
      digitalWrite(segmentos[3], 1);
      digitalWrite(segmentos[4], 1);
      digitalWrite(segmentos[5], 0);
      digitalWrite(segmentos[6], 1);
      break;
    case '3':
      // Representación del número 3
      digitalWrite(segmentos[0], 1);
      digitalWrite(segmentos[1], 1);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 1);
      digitalWrite(segmentos[4], 0);
      digitalWrite(segmentos[5], 0);
      digitalWrite(segmentos[6], 1);
      break;
    case '4':
      // Representación del número 4
      digitalWrite(segmentos[0], 0);
      digitalWrite(segmentos[1], 1);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 0);
      digitalWrite(segmentos[4], 0);
      digitalWrite(segmentos[5], 1);
      digitalWrite(segmentos[6], 1);
      break;
    case '5':
      // Representación del número 5
      digitalWrite(segmentos[0], 1);
      digitalWrite(segmentos[1], 0);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 1);
      digitalWrite(segmentos[4], 0);
      digitalWrite(segmentos[5], 1);
      digitalWrite(segmentos[6], 1);
      break;
    case '6':
      // Representación del número 6
      digitalWrite(segmentos[0], 1);
      digitalWrite(segmentos[1], 0);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 1);
      digitalWrite(segmentos[4], 1);
      digitalWrite(segmentos[5], 1);
      digitalWrite(segmentos[6], 1);
      break;
    case '7':
      // Representación del número 7
      digitalWrite(segmentos[0], 1);
      digitalWrite(segmentos[1], 1);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 0);
      digitalWrite(segmentos[4], 0);
      digitalWrite(segmentos[5], 0);
      digitalWrite(segmentos[6], 0);
      break;
    case '8':
      // Representación del número 8
      digitalWrite(segmentos[0], 1);
      digitalWrite(segmentos[1], 1);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 1);
      digitalWrite(segmentos[4], 1);
      digitalWrite(segmentos[5], 1);
      digitalWrite(segmentos[6], 1);
      break;
    case '9':
      // Representación del número 9
      digitalWrite(segmentos[0], 1);
      digitalWrite(segmentos[1], 1);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 1);
      digitalWrite(segmentos[4], 0);
      digitalWrite(segmentos[5], 1);
      digitalWrite(segmentos[6], 1);
      break;
    case '*':
      // Representación del asterisco
      digitalWrite(segmentos[0], 0);
      digitalWrite(segmentos[1], 0);
      digitalWrite(segmentos[2], 0);
      digitalWrite(segmentos[3], 0);
      digitalWrite(segmentos[4], 0);
      digitalWrite(segmentos[5], 0);
      digitalWrite(segmentos[6], 0);
      digitalWrite(segmentos[7], 0);
      break;

      case 'A':
      // Representación del asterisco
      digitalWrite(segmentos[0], 1);
      digitalWrite(segmentos[1], 1);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 0);
      digitalWrite(segmentos[4], 1);
      digitalWrite(segmentos[5], 1);
      digitalWrite(segmentos[6], 1);
      digitalWrite(segmentos[7], 1);
      break;

      case 'B':
      // Representación del asterisco
      digitalWrite(segmentos[0], 1);
      digitalWrite(segmentos[1], 1);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 1);
      digitalWrite(segmentos[4], 1);
      digitalWrite(segmentos[5], 1);
      digitalWrite(segmentos[6], 1);
      digitalWrite(segmentos[7], 1);
      break;

      case 'C':
      // Representación del asterisco
      digitalWrite(segmentos[0], 1);
      digitalWrite(segmentos[1], 0);
      digitalWrite(segmentos[2], 0);
      digitalWrite(segmentos[3], 1);
      digitalWrite(segmentos[4], 1);
      digitalWrite(segmentos[5], 1);
      digitalWrite(segmentos[6], 0);
      digitalWrite(segmentos[7], 1);
      break;

      case 'D':
      // Representación del asterisco
      digitalWrite(segmentos[0], 1);
      digitalWrite(segmentos[1], 1);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 1);
      digitalWrite(segmentos[4], 1);
      digitalWrite(segmentos[5], 1);
      digitalWrite(segmentos[6], 0);
      digitalWrite(segmentos[7], 1);
      break;
      
      case '#':
      // Representación del asterisco
      digitalWrite(segmentos[0], 0);
      digitalWrite(segmentos[1], 1);
      digitalWrite(segmentos[2], 1);
      digitalWrite(segmentos[3], 0);
      digitalWrite(segmentos[4], 1);
      digitalWrite(segmentos[5], 1);
      digitalWrite(segmentos[6], 1);
      digitalWrite(segmentos[7], 1);
      break;
  }
}

void loop() {
  // Mostrar los números del 0 al 9 en el display
  char tecla_presionada = teclado1.waitForKey();
  if (tecla_presionada != '*') digitalWrite(segmentos[7], 1);
  if (tecla_presionada) mostrarNumero(tecla_presionada);
  delay(250);
}
