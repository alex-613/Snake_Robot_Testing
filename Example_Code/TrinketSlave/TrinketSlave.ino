#include <TinyWireS.h>
#define SLAVE_ADDR 10
int led = 1;
//Variable for received data
int rd;
// Variable for blink rate
int br;

void setup()
{
  TinyWireS.begin(SLAVE_ADDR);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop()
{
  while(0 < TinyWireS.available())
  {
    rd = TinyWireS.receive();
    br = map(rd,1,255,100,2000);

    digitalWrite(led,HIGH);
    delay(br);
    digitalWrite(led,LOW);
    delay(br);

  }
}
