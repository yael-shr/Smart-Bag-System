#include <DFRobot_HX711.h> // הספרייה שציינת בספר [cite: 278]

// הגדרת הפינים עבור ה-Pro Micro לפי השרטוט [cite: 279]
// DT מחובר ל-A2, SCK מחובר ל-A3
DFRobot_HX711 MyScale(A2, A3); 

void setup() {
    // אתחול התקשורת הטורית למקמ"ש (Transceiver)
    // ב-Pro Micro משתמשים ב-Serial1 עבור הפינים הפיזיים TX/RX [cite: 210]
    Serial1.begin(9600); 
    
    delay(500); // זמן התייצבות לחיישן
}

void loop() {
    // 1. קריאת המשקל הנוכחי מהחיישן [cite: 290]
    int currentWeight = MyScale.readWeight();

    // 2. שידור המשקל לבקר ה-Uno דרך המקמ"ש [cite: 71, 74]
    // המידע נשלח בצורה טורית בקצב שקבענו [cite: 211, 496]
    if (currentWeight >= 0) {
        Serial1.write(currentWeight); 
    }

    // 3. השהייה קצרה כדי לא להעמיס על התקשורת האלחוטית
    delay(500); 
}