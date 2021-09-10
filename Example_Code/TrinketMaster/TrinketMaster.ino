#include <TinyWireM.h>
#define SWITCH 3
#define LED 4
void setup()
{
  TinyWireM.begin();
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT);
  digitalWrite(SWITCH, HIGH);
}

void loop()
{
  if (! digitalRead(SWITCH)) {
    digitalWrite(LED, HIGH);
    TinyWireM.beginTransmission(4);
    TinyWireM.send(1);
    TinyWireM.endTransmission();
    TinyWireM.beginTransmission(5);
    TinyWireM.send(1);
    TinyWireM.endTransmission();
  } 
  else {
    digitalWrite(LED, LOW);
    TinyWireM.beginTransmission(4);
    TinyWireM.send(0);
    TinyWireM.endTransmission();
    TinyWireM.beginTransmission(5);
    TinyWireM.send(0);
    TinyWireM.endTransmission();
  }
}
