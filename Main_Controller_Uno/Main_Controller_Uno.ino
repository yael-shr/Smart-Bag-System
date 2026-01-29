// חיבור הקבצים שיצרת בלשוניות
#include "DistanceSensor.h"
#include "BagDispenser.h"
#include "SmartScale.h"
#include "DisplayManager.h"
#include <Adafruit_ILI9341.h>

// הגדרת קבועים לפי ספר הפרויקט
#define DISTANCE_THRESHOLD 7 // מרחק סף בס"מ [cite: 334]
#define WEIGHT_LIMIT 20      // משקל מקסימלי בגרמים [cite: 333]

// יצירת אובייקט המסך לפי הספרייה החדשה
Adafruit_ILI9341 tft = Adafruit_ILI9341(10, 9, 7); // 

// יצירת האובייקטים (הגדרת הפינים לפי השרטוטים שלך)
DistanceSensor ultrasonic(9, 8);  // trig=9, echo=8 [cite: 337]
BagDispenser motor(A1, 0, 10);    // כיוון A1, מהירות 10 [cite: 345, 385]
SoftwareSerial mySerial(A5, A4); // פיני RX ו-TX לחיבור המקמ"ש [cite: 335]
SmartScale scale(mySerial);         // נתונים A2, שעון A3 [cite: 279]
DisplayManager display(tft);      // מנהל התצוגה שלנו

int bagCounter = 0; // מונה שקיות [cite: 338]

void setup() {
    Serial.begin(9600); // אתחול תקשורת טורית [cite: 349]
    
    // אתחול כל רכיב דרך המחלקה שלו
    ultrasonic.init(); 
    motor.init();
    scale.init();
    display.init(); // מפעיל את המסך ומציג הודעת פתיחה

    Serial.println("System Initialized...");
}

void loop() {
    // לוגיקה מרכזית: האם השקית מלאה או כבדה מדי?
    bool isFull = ultrasonic.readDistance() <= DISTANCE_THRESHOLD; // [cite: 442]
    bool isHeavy = scale.getWeight() >= WEIGHT_LIMIT;              // [cite: 447]

    if (isFull || isHeavy) { 
        Serial.println("Bag is full! Deploying next bag...");
        
        motor.releaseOneBag(); // הוצאת שקית [cite: 381, 455]
        bagCounter++;          // קידום המונה [cite: 382, 456]
        display.updateBagCount(bagCounter); // עדכון המסך במונה החדש
        
        Serial.print("Bags used: ");
        Serial.println(bagCounter);
    }

    delay(200); // השהייה קלה למניעת קריאות כפולות
}