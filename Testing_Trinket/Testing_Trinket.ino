//This script is purely for testing on the trinket
#include <TinyWireS.h>
#define Slave_ADDR 10

//Now in the slave we need to echo what ever is sent to us by the master
byte echo = 8;

void setup() {
  // put your setup code here, to run once:
  TinyWireS.begin(Slave_ADDR);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(0<TinyWireS.available()){
  TinyWireS.send(echo);
  //}
  //delay(1000);
}
