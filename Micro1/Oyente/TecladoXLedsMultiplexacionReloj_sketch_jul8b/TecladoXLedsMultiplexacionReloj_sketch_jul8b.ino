#include <Keypad.h>

const byte ROWS=4;
const byte COLS=3;
char keys[ROWS][COLS]={
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};
byte rowPins[ROWS]={9, 10, 11, 12}; 
byte colPins[COLS]={13, A4, A5};
 
Keypad keypad=Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int reloj[4]={0, 0, 0, 0};
char teclas[4];

void setup()
{
  for(int i=2; i<9; i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
}
void loop()
{
  teclado();
  mostrar();
}
void limpiar(){
  digitalWrite(A0,HIGH);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,HIGH);
}
void teclado()
{
  char key=keypad.getKey();
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
void mostrar()
{ 
  limpiar();
  impDis(reloj[0],8);
  digitalWrite(A3,LOW);
  digitalWrite(A2,HIGH);
  digitalWrite(A1,HIGH);
  digitalWrite(A0,HIGH);
  limpiar();

  limpiar();
  impDis(reloj[1],8);
  digitalWrite(A3,HIGH);
  digitalWrite(A2,LOW);
  digitalWrite(A1,HIGH);
  digitalWrite(A0,HIGH);
  limpiar();
  
  limpiar();
  impDis(reloj[2],8);
  digitalWrite(A3,HIGH);
  digitalWrite(A2,HIGH);
  digitalWrite(A1,LOW);
  digitalWrite(A0,HIGH);
  limpiar();
  
  limpiar();
  impDis(reloj[2],8);
  digitalWrite(A3,HIGH);
  digitalWrite(A2,HIGH);
  digitalWrite(A1,HIGH);
  digitalWrite(A0,LOW);
  limpiar();
}