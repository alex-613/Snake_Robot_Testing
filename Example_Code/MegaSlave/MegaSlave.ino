#include <Wire.h>

void setup() {
  Wire.begin(5);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
    while(0 < Wire.available())
  {
    byte c = Wire.read();
    Serial.println(c);
    if (0 == c) {    
      digitalWrite(13, HIGH);
    }
    else {    
      digitalWrite(13, LOW); 
    }  
  }
}
