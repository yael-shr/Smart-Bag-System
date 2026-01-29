#ifndef SMART_SCALE_H
#define SMART_SCALE_H

#include <Arduino.h>
#include <SoftwareSerial.h> // שימוש בספרייה לניהול התקשורת מהמקמ"ש [cite: 216]

class SmartScale {
private:
    SoftwareSerial& scaleSerial; // רפרנס לחיבור הטורי של המקמ"ש
    const int weightLimit = 20;  // משקל סף להוצאת שקית [cite: 333, 447]
    int lastReadWeight = 0;

public:
    // בנאי המקבל את אובייקט ה-SoftwareSerial
    SmartScale(SoftwareSerial& serial) : scaleSerial(serial) {}

    void init() {
        scaleSerial.begin(9600); // קצב תקשורת 9600bps כפי שמדדת בסקופ [cite: 211, 295]
    }

    // פונקציה שבודקת אם הגיע נתון חדש מה-Pro Micro
    void update() {
        if (scaleSerial.available()) {
            delay(10); // השהיה קלה להבטחת הגעת כל הביטים 
            lastReadWeight = scaleSerial.read(); // קריאת הנתון שנשלח [cite: 229]
            
            Serial.print("Received Weight: ");
            Serial.println(lastReadWeight);
        }
    }

    int getWeight() {
        return lastReadWeight;
    }

    // בדיקה האם המשקל חורג מהמותר [cite: 441, 447]
    bool isOverweight() {
        update(); // עדכון לפני הבדיקה
        return lastReadWeight >= weightLimit;
    }
};

#endif