#ifndef SMART_SCALE_H
#define SMART_SCALE_H

#include <Arduino.h>
#include <SoftwareSerial.h> 

class SmartScale {
private:
    SoftwareSerial& scaleSerial; 
    const int weightLimit = 20;  
    int lastReadWeight = 0;

public:
    SmartScale(SoftwareSerial& serial) : scaleSerial(serial) {}

    void init() {
        scaleSerial.begin(9600); 
    }

    void update() {
        if (scaleSerial.available()) {
            delay(10); 
            lastReadWeight = scaleSerial.read(); 
            
            Serial.print("Received Weight: ");
            Serial.println(lastReadWeight);
        }
    }

    int getWeight() {
        return lastReadWeight;
    }

    bool isOverweight() {
        update();
        return lastReadWeight >= weightLimit;
    }
};

#endif
