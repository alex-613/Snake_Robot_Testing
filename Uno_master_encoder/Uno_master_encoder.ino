#include <Wire.h>
#define SLAVE_ADDR 10

// Analogue pin for potentiometer
int analogPin = 0;
byte val = 0;
int val_previous = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  
}

void loop() {
  //delay(50);

  //Read the pot value and then map it to 1-255 for the flash rate
  //val = map(analogRead(analogPin),0,  1023, 255, 1);
    
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(val);
  Wire.endTransmission();
  //Serial.println("data sent!");

  Wire.requestFrom(SLAVE_ADDR,8);
  if (0<Wire.available()){
    val = Wire.read();
    Serial.println(val);
  }
}
