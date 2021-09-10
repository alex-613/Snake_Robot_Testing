#include "PinChangeInterrupt.h"

#define interruptPin 3
#define LEDpin 1 

void setup() {
  pinMode(interruptPin,INPUT);
  pinMode(LEDpin, OUTPUT);

  attachPCINT(digitalPinToPCINT(interruptPin), blinkLed, RISING);
}

void blinkLed(void){
  digitalWrite(LEDpin, !digitalRead(LEDpin));
}

void loop() {
  // put your main code here, to run repeatedly:

}
