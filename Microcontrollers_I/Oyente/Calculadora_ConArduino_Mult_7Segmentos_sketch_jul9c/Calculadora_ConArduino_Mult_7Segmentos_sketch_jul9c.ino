// C++ code
#include <Keypad.h>

const byte FILAS = 4;
const byte COLUMNAS = 3;

char teclas[FILAS][COLUMNAS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte pinesFilas[FILAS] = {9, 10, 11, 12};
byte pinesColumnas[COLUMNAS] = {13, A2, A3};

Keypad keypad = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, FILAS, COLUMNAS);

// Definición de los pines del display
const int segmentos[] = {2, 3, 4, 5, 6, 7, 8};

// Definición de los patrones de los segmentos para cada número
const byte numeros[][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};

// Definición de los pines comunes
const int displays[2] = {A0, A1};

void setup()
{
  // Setteo la comunicacion Serial a 9600 Bauds
  Serial.begin(9600);

  // Set de OUTPUTS
  for (int i = 0; i < 8; i++) {
  	pinMode(segmentos[i], OUTPUT);
    digitalWrite(segmentos[i], HIGH);
  }
  for (int i = 0; i < 2; i++) {
  	pinMode(displays[i], OUTPUT);
    digitalWrite(displays[i], HIGH);
  }
  
}

void loop()
{
  limpiar();
  // digitalWrite(displays[0], HIGH);
  // digitalWrite(displays[1], LOW);
  // nums();
  // digitalWrite(displays[0], LOW);
  // digitalWrite(displays[1], HIGH);
  // nums();

  calc();
}

void calc() {
  char tecla = keypad.getKey();

  if (tecla) {
    Serial.println("Tecla presionada: " + String(tecla));
    
    switch (tecla) {
      // suma //
      case '1': {
        sumar();
      } break;

      // // resta //
      // case '2': {} brak;
      // case '1': {} brak;

    }
  }
}

void sumar() {
  Serial.println("Operación de suma");
  int a = obtenerNumero();
  int b = obtenerNumero();
  int resultado = a + b;
  Serial.println("Resultado: " + String(resultado));
  Serial.println("Send any character to continue");
  while (Serial.available() <= 0) {
    mostrarEnDisp(resultado);
  }; // Esperar hasta que haya datos disponibles
}

int obtenerNumero() {
  int numero = 0;
  char tecla;

  Serial.println("Ingrese un número (terminar con #):");
  while ((tecla = keypad.getKey()) != '#') {
    if (tecla) {
      Serial.print(tecla);
      numero = numero * 10 + (tecla - '0');
    }
  }
  Serial.println();
  return numero;
}

void mostrarEnDisp(int num) {
  limpiar();
  int t = 20;

  if (num < 10) {

    // Display 1
    digitalWrite(displays[0], LOW);
    digitalWrite(displays[1], HIGH);
    mostrarNumero(num);
  } else if (num > 9 && num < 100) {
    // Display 1
    digitalWrite(displays[0], LOW);
    digitalWrite(displays[1], HIGH);
    mostrarNumero(num%10);  // Obtener la unidad del número
    delay(t);
    // Display 2
    digitalWrite(displays[0], HIGH);
    digitalWrite(displays[1], LOW);
    mostrarNumero((num / 10) % 10); // Obtener la decena del número
    delay(t);
  }
}

void nums() {
  int t = 250;
  // Mostrar los números del 1 al 9 en el display
  for (int numero = 1; numero <= 9; numero++) {
    mostrarNumero(numero);
    delay(t); // Esperar 1 segundo antes de cambiar al siguiente número
  }

  digitalWrite(displays[0], LOW);
  digitalWrite(displays[1], LOW);
}

void prueba17() {
  int t = 10;
  limpiar();
  digitalWrite(displays[0], LOW);
  digitalWrite(displays[1], LOW);
  
  delay(t);
  digitalWrite(displays[0], HIGH);
  digitalWrite(displays[1], LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);

  
  delay(t);
  digitalWrite(displays[0], LOW);
  digitalWrite(displays[1], HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(2, HIGH);
  delay(t);
}

void limpiar() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentos[i], LOW);
  }
}

// void lightSegments(int number) {
//   byte numberBit = numbersDisplayAnode[number];
//   for (int i = 0; i < 7; i++)  {
//     int bit = bitRead(numberBit, i);
//     digitalWrite(segmentos[i], bit);
//   }
// }


// Función para mostrar un número en el display
void mostrarNumero(int numero) {
  // Verificar que el número esté en el rango válido
  if (numero >= 0 && numero <= 9) {
    // Encender los segmentos correspondientes al número
    for (int i = 0; i < 7; i++) {
      digitalWrite(segmentos[i], numeros[numero][i]);
    }
  }
}
