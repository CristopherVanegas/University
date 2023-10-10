#include <DHT.h> //declaracion de la libreria para el uso del sensor de humedad
// declaracion de variables a utlizar...
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int sensor = 0;
int humedad;
int bomba = 7;
int ldrpin = 0;
int ldrvar = 0;
int conta = 0;
int on = 0;
int tempo = 100;
int encendido = 9;
DHT dht (sensor, DHT11);
//activacion de puertos de salida y variables del sensor de humedad
void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT); 
  pinMode(bomba, OUTPUT); 
  dht.begin();    
}
//logica de programacion
void loop() 
{
  // lectura de los datos del sensor de luminosidad LDR
  ldrvar = analogRead(ldrpin);
  // lectura del estado del switch para encender el sistema
  on = digitalRead (encendido);
  // lectura de los datos del sensor de humedad DTH11
  humedad = dht.readHumidity();
  // Si el switch se encuentra en estado 1, el sistema se encuentra encendido
  // caso contrario no funciona nada del sistema.
  if (on == 1)
  {
    // mediante la conversion analoga-digital del sensor de luminosidad
    // se ejecutar comparaciones para validar los parametros solicitados
    // en el proyecto (conversion 5v a 1023 bits).
    if (ldrvar <=520)
    {
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      // mediante la libreria del sensor de humedad, se tiene la conversion analoga-digital
      // de los datos obtenidos por el sensor, cumpliendo de igual forma los parametros
      // solicitados en el proyecto.
      if (humedad >= 45)
      {
        // en el primer condicional solamente se enciende la luz led correspondiente
        digitalWrite(led4, HIGH);
        digitalWrite(led1, LOW);
        digitalWrite(led5, LOW);         
        digitalWrite(bomba, LOW);
        conta = 0; // se resetea el contador para la segunda condicion solicitada
        // correspondiente al sensor de humedad
      }
      // segunda condicion del sensor de humedad
      if (humedad < 45 && humedad > 40)
      {
        // En este segundo condicional, se enciende la luz correspondiente y se crea un
        // contador que permita encender la bomba durante 10 segundos        
          digitalWrite(led1, LOW);
          digitalWrite(led4, LOW);
          digitalWrite(led5, HIGH);
        // inicializacion del contador para la bomba...   
          while (conta != 100)
          {
            digitalWrite(bomba, HIGH);
            conta++;
            ldrvar = analogRead(ldrpin);
            on = digitalRead (encendido);
            humedad = dht.readHumidity();
            delay (100);
            // las siguientes condicionales detienen el funcionamiento de la bomba 
            // en caso de que la luminosidad este fuera del rango de funcionamiento o 
            // se abra el switch que energiza el sistema 
            if (on == 0 || ldrvar >520 || humedad >= 45)
            {
              conta = 100;
            }
          }                 
          digitalWrite(bomba, LOW);               
      }
      // tercer condicional
      if (humedad <= 40)
      {
        // en esta condicion, se enciende constantemente la bomba y de igual forma su 
        // led indicador.
        conta=0;
        digitalWrite(led5, LOW);         
        digitalWrite(led1, HIGH);
        digitalWrite(led4, LOW);
        digitalWrite(bomba, HIGH);
      }
    }
    // condicional que se cumple en caso de que la luminosidad se encuentre fuera del rango
    // solicitado
    else 
    {
      conta = 0;
      digitalWrite(led3, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);       
      digitalWrite(bomba, LOW);
    }
  }
  // condicional que se cumple en caso de que el sistema se encuentre desenergizado.
  else
  {
    conta = 0;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);     
    digitalWrite(bomba, LOW);
  }
}
