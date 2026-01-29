# Smart Bag Dispenser System 🌍

## Overview
An automated industrial bag dispenser designed to reduce plastic waste through smart sensing and real-time weight/distance monitoring.

## System Architecture
The project utilizes a **Dual-MCU Architecture** to ensure reliable data processing:
* **Master Controller (Arduino Uno):** Orchestrates UI, ultrasonic sensing, and motor control.
* **Sensor Node (Arduino Pro Micro):** Dedicated high-precision weight acquisition and wireless transmission.

## Key Features
* **Modular OOP Design:** Hardware components are abstracted into C++ classes for maintainability.
* **Dual-Sensor Logic:** Deployment is triggered based on distance (ultrasonic) or bag weight thresholds.
* **Wireless Data Link:** Reliable UART communication between controllers at 9600bps.
* **Interactive UI:** High-resolution TFT display showing real-time bag usage statistics.

## Technical Specifications
* **Languages:** C++, Arduino
* **Protocols:** SPI (Display), UART (Inter-MCU), I2C-like (HX711)
* **Components:** HC-SR04, HX711 Load Cell, L293D Motor Driver, ILI9341 TFT.