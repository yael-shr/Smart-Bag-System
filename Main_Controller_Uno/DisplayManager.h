#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Adafruit_GFX.h> 
#include <Adafruit_ILI9341.h> 

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
        tft.setRotation(0); 
        showStartScreen();
    }

    void showStartScreen() {
        tft.fillScreen(BLACK); 
        tft.setTextColor(WHITE);
        tft.setTextSize(2); 
        tft.setCursor(20, 50);
        tft.print("Welcome to SmartBag!"); 
    }

    void updateBagCount(int count) {
        tft.fillScreen(BLACK);
        tft.setCursor(30, 50);
        tft.print("Next bag released"); 
        tft.setCursor(100, 100);
        tft.print("Bag Number: ");
        tft.print(count); 
    }
};

#endif
