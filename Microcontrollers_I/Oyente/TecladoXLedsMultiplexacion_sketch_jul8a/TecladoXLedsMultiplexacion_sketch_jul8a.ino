// Definición de los pines del teclado
#include <Keypad.h>

const byte FILAS = 4;
const byte COLS = 4;

// Definición de la matriz del teclado
char keys[FILAS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


byte fils[] = {9, 10, 11, 12};    // Pines de las filas
byte columnas[] = {13, A4, A5, 9}; // Pines de las columnas

Keypad teclado = Keypad(makeKeymap(keys), fils, columnas, FILAS, COLS);

char TECLA;

//Declaramos los pines qde conexión del display
const int segmentos[7] = { 2, 3, 4, 5, 6, 7, 8 }; 
const int displays[4]= {A3, A2, A1, A0};

//Declaramos los numeros para el ánodo común
const byte numbersDisplayAnode[10] = {0b1000000,     //0
                          0b1111001,          //1
                          0b0100100,          //2
                          0b0110000,          //3
                          0b0011001,          //4
                          0b0010010,          //5
                          0b0000010,          //6
                          0b1111000,          //7
                          0b0000000,          //8
                          0b0010000};         //9

void setup() {
  // Iniciamos la comunicacion serial a 9600 baudios
  Serial.begin(9600);

  // Ponemos los pines como salida
  for(int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);  
  }
  
  // Ponemos los pines A como salida y como HIGH
  for(int i = 0; i < 4; i++) {
    pinMode(displays[i], OUTPUT); 
  }

  // Iniciamos el display en 0
  lightSegments(0);  
}

void loop() {
  TECLA = teclado.getKey();
  Serial.println(TECLA);
  // nums();
  // seg();
  mostrarNumero(23);
}

void nums() {
  for(int i = 0; i < 10; i++) {
    lightSegments(i);
    delay(1000);
  }
}
void lightSegments(int number) {
  byte numberBit = numbersDisplayAnode[number];
  for (int i = 0; i < 7; i++)  {
    int bit = bitRead(numberBit, i);
    digitalWrite(segmentos[i], bit);
  }
}

void mainCalc(char KEY) {
  switch (KEY) {
    // Suma //
    case '1': {
      int a = int(teclado.getKey());
      int b = int(teclado.getKey());
      digitalWrite(displays[0], HIGH);
      lightSegments(a);
    } break;
    // Resta //
    case '2': {} break;
    // Igual //
    case '3': {} break;
  }
}

void seg() {
  // Ciclo para mostrar los dígitos del 0 al 9 en los displays
  for (int digito = 0; digito < 10; digito++) {
    // Mostrar el dígito actual en los displays
    for (int i = 0; i < 4; i++) {
      digitalWrite(displays[i], HIGH); // Apagar todos los displays
    }
    
    for (int segmento = 0; segmento < 7; segmento++) {
      digitalWrite(segmentos[segmento], bitRead(numbersDisplayAnode[digito], segmento));
    }
    
    digitalWrite(displays[digito % 4], LOW); // Encender el display correspondiente al dígito actual
    
    delay(1000); // Retardo para mostrar cada dígito durante 1 segundo
  }
}

void mostrarNumero(int numero) {
  int unidades = numero % 10;
  int decenas = numero / 10;
  
  for (int i = 0; i < 4; i++) {
    digitalWrite(displays[i], HIGH); // Apagar todos los displays
  }
  
  for (int segmento = 0; segmento < 7; segmento++) {
    digitalWrite(segmentos[segmento], bitRead(numbersDisplayAnode[unidades], segmento));
  }
  digitalWrite(displays[0], LOW); // Encender el primer display para las unidades
  
  delay(5); // Pequeño retardo para evitar el parpadeo
  
  for (int segmento = 0; segmento < 7; segmento++) {
    digitalWrite(segmentos[segmento], bitRead(numbersDisplayAnode[decenas], segmento));
  }
  digitalWrite(displays[1], LOW); // Encender el segundo display para las decenas
}




















