#include "zeroCrossing.h"


volatile unsigned int timer1_counter=0;
volatile int state=0;

zeroCrossing::zeroCrossing()
{
  
  }

void handleInterrupt() {
 if(state==0){
   TCNT1=0;
   state=1;
   timer1_counter=0;
 }else{
  timer1_counter=TCNT1;
  state=0;
 }
}

void zeroCrossing::init(const int zcPin)
{
  pinMode(zcPin,INPUT);
  attachInterrupt(digitalPinToInterrupt(zcPin), handleInterrupt, RISING);
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  TCCR1B |= (1 << CS11);//8 as prescalar
}

float zeroCrossing::zeroCrossingFreq(void)
{
if(state==0){
  //Serial.print(timer1_counter);
  //Serial.print(" ");
  freq=timer1_counter*0.000001;//0.000001=2*8/16MHz
  return (1/freq);
 }
 return 0.0;
}

