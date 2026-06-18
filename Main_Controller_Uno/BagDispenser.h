#ifndef BAG_DISPENSER_H
#define BAG_DISPENSER_H

#include <Arduino.h>

class BagDispenser {
private:
    const int dirPin1;   
    const int dirPin2;  
    const int speedPin;  

public:
    BagDispenser(int d1, int d2, int speed) 
        : dirPin1(d1), dirPin2(d2), speedPin(speed) {}

    void init() {
        pinMode(dirPin1, OUTPUT);
        pinMode(dirPin2, OUTPUT);
        pinMode(speedPin, OUTPUT);
    }

\    void releaseOneBag() {
        digitalWrite(dirPin1, HIGH); 
        digitalWrite(dirPin2, LOW);  
        
        analogWrite(speedPin, 225);  
        
        delay(1000); 
        
        stop();
    }

    void stop() {
        analogWrite(speedPin, 0);
        digitalWrite(dirPin1, LOW);
        digitalWrite(dirPin2, LOW);
    }
};

#endif
