#include <Wire.h>
#define SLAVE_ADDR 10

// Analogue pin for potentiometer
int analogPin = 0;
int val = 0;
int val_previous = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  
  delay(50);
  
  //Read the pot value and then map it to 1-255 for the flash rate
  val = map(analogRead(analogPin),0,  1023, 255, 1);

  if (val == val_previous){
    // Do nothing
    //Serial.println("No change!");
  }

  if (val != val_previous){
      //Write a character to the Slave
    Serial.println(val);
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(val);
    Wire.endTransmission();
  }

  val_previous = val;
  

}
