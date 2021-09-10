#include <TinyWireS.h>
//Slave Address
#define SLAVE_ADDR 10
//Input channel 1 and 2 for setting motor direction
#define IN1 1
#define IN2 4
//Channel A from the encoder
#define ChA 3
//Number of encoder counts per revolution
const long ENC_COUNT_REV = 894;

//macro for detection af rasing edge
#define RE(signal, state) (state=(state<<1)|(signal&1)&3)==1

//macro for detection af falling edge
#define FE(signal, state) (state=(state<<1)|(signal&1)&3)==2

//Temporary variable for the byte received from the master used to control motor speed
byte byteRcvd = 0;
//Variable for the RPM measurement
byte rpm = 0;
//Volatile variable that is used to record the encoder counts 
volatile long encoderValue = 0;
volatile int revs = 0;
//One second interval for measurements
int interval = 1000;


//Counters for milliseconds during interval
long previousMillis = 0;
long currentMillis = 0;

//Variable for PWM motor speed output
int motorPwm;

//Previous state of the encoder
bool prevEncState = 0;
bool currentEncState = 0;
void setup() {
  // put your setup code here, to run once:
  TinyWireS.begin(SLAVE_ADDR);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ChA, INPUT);
  previousMillis = millis();
}

void loop() {
  analogWrite(IN1,60);
  // put your main code here, to run repeatedly:
 while(0<TinyWireS.available()){
   byteRcvd = TinyWireS.receive();
   //currentEncState = digitalRead(ChA);
   if((prevEncState == 0) && (digitalRead(ChA) == 1))
   {
   encoderValue++;
   //prevEncState = digitalRead(ChA);
    }  
    prevEncState = digitalRead(ChA);
    //encoderValue = (int)(encoderValue/2);
    //rpm = (float)(encoderValue * 60/ ENC_COUNT_REV);
    revs = (int)(encoderValue/ENC_COUNT_REV);

    
    
    TinyWireS.send(revs); // The send command only works when you have received a requestFrom command from the master, or else it wont work!!!!
     //encoderValue = 0;  
  
   
  }



  
}
