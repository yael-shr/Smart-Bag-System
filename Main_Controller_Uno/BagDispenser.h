#ifndef BAG_DISPENSER_H
#define BAG_DISPENSER_H

#include <Arduino.h>

class BagDispenser {
private:
    const int dirPin1;   // פין כיוון 1 (למשל A1 מהספר שלך)
    const int dirPin2;   // פין כיוון 2 (בדרך כלל אדמה או פין בקרה נוסף)
    const int speedPin;  // פין ה-PWM (פין 10 מהספר שלך)

public:
    // בנאי: מקבל את מספרי הפינים ושומר אותם
    BagDispenser(int d1, int d2, int speed) 
        : dirPin1(d1), dirPin2(d2), speedPin(speed) {}

    // הכנת הפינים לעבודה (מוגדרים כ-OUTPUT)
    void init() {
        pinMode(dirPin1, OUTPUT);
        pinMode(dirPin2, OUTPUT);
        pinMode(speedPin, OUTPUT);
    }

    // הפעולה המרכזית: מוציאה שקית אחת ועוצרת
    void releaseOneBag() {
        // קביעת הכיוון לפי טבלת האמת בספר
        digitalWrite(dirPin1, HIGH); 
        digitalWrite(dirPin2, LOW);  
        
        // קביעת המהירות (225 מתוך 255)
        analogWrite(speedPin, 225);  
        
        // סיבוב למשך שנייה אחת (זמן שקבעת להוצאת שקית)
        delay(1000); 
        
        // עצירה מוחלטת של המנוע
        stop();
    }

    void stop() {
        analogWrite(speedPin, 0);
        digitalWrite(dirPin1, LOW);
        digitalWrite(dirPin2, LOW);
    }
};

#endif