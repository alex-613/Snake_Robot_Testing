//This script is purely for testing
#include <Wire.h>
#define Slave_ADDR 10
//Define a variable
int randomnumber = 5;
byte echo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
}

void loop() {

  Wire.beginTransmission(Slave_ADDR);
  Wire.write(1);
  Wire.endTransmission();
  Wire.requestFrom(Slave_ADDR, 8);
  //Uno sends a request to the trinket
  while (0<Wire.available()){
    echo = Wire.read();
    Serial.println(echo);
  }
  
  //Receives info back
}
