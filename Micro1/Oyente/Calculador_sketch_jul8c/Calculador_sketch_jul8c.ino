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
  // TECLA = teclado.getKey();
  Serial.println(TECLA);
  // nums();
  // seg();
  // mostrarNumero(23);
  mainCalc();
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
      Serial.println("Operando 1");
      int a = teclado.getKey().toInt;
      impDis(reloj[0], a);
      Serial.println("Operando 2");
      int b = teclado.getKey().toInt;
      impDis(reloj[1], b);
    } break;
    // Resta //
    case '2': {} break;
    // Igual //
    case '3': {} break;
  }
}
void limpiar(){
  digitalWrite(A0,HIGH);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,HIGH);
}
void teclado()
{
  char key = teclado.getKey();
  if(key!=NO_KEY)
  {
    if(key!='*' && key!='#')
    {
      teclas[0]=key;
      String caracter;
      int entero;
      for(int i=0; i<1; i++)
      {
      caracter=caracter+teclas[0]; 
      entero=caracter.toInt();
      }
    reloj[3]=reloj[2];
    reloj[2]=reloj[1];
    reloj[1]=reloj[0];
    reloj[0]=entero;
    }
  }
}
void impDis(int num, int g){
  int arreglo[]={126, 48, 109, 121, 51, 91, 31, 112, 127,
                115, 0, 79, 21, 61};
  for(int i=0; i<7; i++)
  digitalWrite(g-i, bitRead(arreglo[num], i)); 
}


















