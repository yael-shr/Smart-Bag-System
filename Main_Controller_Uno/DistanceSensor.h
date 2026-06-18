#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include <Arduino.h>

class DistanceSensor {
private:
    const int trigPin;
    const int echoPin; 
    const int threshold = 7; 

public:
    DistanceSensor(int trig, int echo) : trigPin(trig), echoPin(echo) {}

    void init() {
        pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);  
    }

    int readDistance() {
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10); 
        digitalWrite(trigPin, LOW);

        long duration = pulseIn(echoPin, HIGH); 
        int distance = duration / 58; 
        return distance;
    }

    bool isFull() {
        return readDistance() <= threshold; 
    }
};

#endif
