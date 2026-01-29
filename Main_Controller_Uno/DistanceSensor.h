#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include <Arduino.h>

class DistanceSensor {
private:
    const int trigPin; // הדק מוצא לדרבון [cite: 253]
    const int echoPin; // הדק מבוא לקבלת הד [cite: 253]
    const int threshold = 7; // מרחק סף בס"מ לפי הגדרת DIS [cite: 334]

public:
    // בנאי - מגדיר איזה פינים מחוברים [cite: 252]
    DistanceSensor(int trig, int echo) : trigPin(trig), echoPin(echo) {}

    // אתחול מצב הפינים
    void init() {
        pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);  
    }

    // הפעולה המרכזית שדוגמת את המרחק [cite: 253]
    int readDistance() {
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10); // פולס ברוחב 10 מיקרו-שנייה [cite: 253]
        digitalWrite(trigPin, LOW);

        long duration = pulseIn(echoPin, HIGH); // מדידת זמן חזרת ההד
        int distance = duration / 58; // חישוב לפי מהירות הקול [cite: 251, 398]
        return distance;
    }

    // בדיקה האם השקית מלאה
    bool isFull() {
        return readDistance() <= threshold; 
    }
};

#endif