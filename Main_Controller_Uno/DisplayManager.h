#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Adafruit_GFX.h>    // ספריית הגרפיקה הכללית
#include <Adafruit_ILI9341.h> // הספרייה שהתקנת הרגע

// הגדרת צבעים לפי ה-Datasheet [cite: 184]
#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800

class DisplayManager {
private:
    Adafruit_ILI9341& tft;

public:
    DisplayManager(Adafruit_ILI9341& display) : tft(display) {}

    void init() {
        tft.begin();
        tft.setRotation(0); // הגדרת כיוון [cite: 185]
        showStartScreen();
    }

    void showStartScreen() {
        tft.fillScreen(BLACK); // ניקוי מסך [cite: 152, 184]
        tft.setTextColor(WHITE);
        tft.setTextSize(2); // גודל גופן [cite: 186]
        tft.setCursor(20, 50);
        tft.print("Welcome to SmartBag!"); // הודעת פתיחה [cite: 361-363]
    }

    void updateBagCount(int count) {
        tft.fillScreen(BLACK);
        tft.setCursor(30, 50);
        tft.print("Next bag released"); // [cite: 376]
        tft.setCursor(100, 100);
        tft.print("Bag Number: ");
        tft.print(count); // הצגת המונה [cite: 378]
    }
};

#endif