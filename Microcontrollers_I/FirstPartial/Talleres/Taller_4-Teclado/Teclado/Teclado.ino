// Taller 4 - Keypad  |   Integrantes:  Cristopher Vera - Victor Vergara - Cristopher Vanegas - Emilio Aguirre //

#include <Keypad.h>
const byte filas = 4, columnas = 4;
byte pinesFilas[] = { 9, 8, 7, 6 }, pinesColumnas[] = { 5, 4, 3, 2 };
char teclas[4][4] = { { '1', '2', '3', 'A' }, { '4', '5', '6', 'B' }, { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' } };

Keypad teclado1 = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);

void setup() {
  Serial.begin(9600);
  Serial.println("Teclado 4x4 \n");
}

void loop() {
  char tecla_presionada = teclado1.getKey();  //Verifica si alguna tecla fue presionada
  if (tecla_presionada) Serial.print("Tecla: " + String(tecla_presionada) + "\n");  //Monitor Serial
}