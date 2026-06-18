#include "DistanceSensor.h"
#include "BagDispenser.h"
#include "SmartScale.h"
#include "DisplayManager.h"
#include <Adafruit_ILI9341.h>

#define DISTANCE_THRESHOLD 7
#define WEIGHT_LIMIT 20

Adafruit_ILI9341 tft = Adafruit_ILI9341(10, 9, 7); 

DistanceSensor ultrasonic(9, 8);  
BagDispenser motor(A1, 0, 10);   
SoftwareSerial mySerial(A5, A4);
SmartScale scale(mySerial);        
DisplayManager display(tft);

int bagCounter = 0;

void setup() {
    Serial.begin(9600); 
    
    ultrasonic.init(); 
    motor.init();
    scale.init();
    display.init(); 

    Serial.println("System Initialized...");
}

void loop() {
    bool isFull = ultrasonic.readDistance() <= DISTANCE_THRESHOLD; 
    bool isHeavy = scale.getWeight() >= WEIGHT_LIMIT;            

    if (isFull || isHeavy) { 
        Serial.println("Bag is full! Deploying next bag...");
        
        motor.releaseOneBag(); 
        bagCounter++;        
        display.updateBagCount(bagCounter); 
        
        Serial.print("Bags used: ");
        Serial.println(bagCounter);
    }

    delay(200); 
}
