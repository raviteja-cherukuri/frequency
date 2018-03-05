#ifndef zeroCrossing_h
#define zeroCrossing_h
 
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif



class zeroCrossing {
public:
	zeroCrossing();
	float freq=0.0;
	float zeroCrossingFreq(void);
    void init(const int zcPin );
};
#endif
