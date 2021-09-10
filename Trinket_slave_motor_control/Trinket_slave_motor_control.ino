#include <TinyWireS.h>
#define SLAVE_ADDR 10
#define IN1 1
#define IN2 4
#define ChA 3
#define ENC_COUNT_REV 894
int rd;
volatile long encoderValue = 0;
int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;
int rpm = 0;


void setup() {
  // put your setup code here, to run once:
  TinyWireS.begin(SLAVE_ADDR);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ChA, INPUT);

}

void loop() {
    while(0 < TinyWireS.available())
  {
    rd = TinyWireS.receive();
    analogWrite(IN1,rd); //Going forwards
    //analogWrite(IN2,rd); //Going backwards 
  }

//   if(digitalRead(ChA)){
//    encoderValue++;
//    if (encoderValue == 894){
//      encoderValue = 0;
//      rpm++;
//    }
//  }

//   TinyWireS.send(rpm);

    

}
