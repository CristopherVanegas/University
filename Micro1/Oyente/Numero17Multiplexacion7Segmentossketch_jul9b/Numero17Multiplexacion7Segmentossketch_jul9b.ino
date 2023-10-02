// C++ code
//

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

const int segmentos[7] = { 2, 3, 4, 5, 6, 7, 8 }; 
const int displays[2] = {A0, A1};

void setup()
{
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

void lightSegments(int number) {
  byte numberBit = numbersDisplayAnode[number];
  for (int i = 0; i < 7; i++)  {
    int bit = bitRead(numberBit, i);
    digitalWrite(segmentos[i], bit);
  }
}
