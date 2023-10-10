#include <SoftwareSerial.h>

SoftwareSerial miBT(10, 11);  // RX->10 / TX->11

/*    AT COMMANDS    */
// AT+NAME? -> Nombre del BT
// AT+PSWD? -> PIN/PASSWORD asignada
// AT+ROLE? -> 0 SLAVE / 1 MASTER
// AT+UART? -> UART CONN / BAUDIOS CONFIGURATION

// AT+ORGL  -> TO START CONFIGURATION
// AT+NAME=VALERY -> SET NAME TO 'VALERY'
// AT+PSWD=1234   -> SET PIN/PASSWORD
// AT+ROLE=0      -> SET ROLE TO SLAVE
// AT+UART=38400,0,0 -> UART CONN / BAUDIOS CONFIGURATION

// AT+RESET -> EXIT CONFIGURATION MODE

void setup() {
  Serial.begin(9600);
  Serial.println("Listo");
  miBT.begin(9600);
}

void loop() {
  if (miBT.available()) Serial.write(miBT.read());

  if (Serial.available()) miBT.write(Serial.read());
}
