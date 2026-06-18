#include <DFRobot_HX711.h>


DFRobot_HX711 MyScale(A2, A3); 

void setup() {
    
    Serial1.begin(9600); 
    
    delay(500);  
}

void loop() {
    int currentWeight = MyScale.readWeight();


    if (currentWeight >= 0) {
        Serial1.write(currentWeight); 
    }

    delay(500); 
}
