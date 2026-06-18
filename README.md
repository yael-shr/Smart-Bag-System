# Smart Bag Dispenser System 🌍

## Overview
An automated industrial bag dispenser designed to reduce plastic waste through smart sensing and real-time weight/distance monitoring.

## System Architecture
The project utilizes a Dual-MCU Architecture to ensure reliable, high-performance data processing:
* **Master Controller (Arduino Uno):** Orchestrates UI, ultrasonic sensing, and motor control.
* **Sensor Node (Arduino Pro Micro):** Dedicated high-precision weight acquisition and wireless transmission.

## Key Features
* **Modular OOP Design:** Hardware components are abstracted into C++ classes for high maintainability and clean encapsulation.
* **Interrupt-Driven Real-Time Execution:** Utilizes hardware interrupts for non-blocking, immediate response to physical sensor changes, optimizing CPU utilization.
* **Dual-Sensor Logic:** Deployment is triggered based on distance (ultrasonic) or bag weight thresholds.
* **Wireless Data Link:** Reliable wireless UART communication between controllers at 9600bps using specialized RF transceivers.
* **Interactive UI:** High-resolution TFT display showing real-time bag usage statistics via hardware SPI.

## Debugging & Challenges
* **Signal Noise & Debouncing:** Handled mechanical sensor bounce and signal noise by implementing custom software debouncing algorithms and validation thresholds, preventing false interrupt triggers.
* **Asynchronous Wireless Data Loss:** Solved potential packet corruption over the wireless link by introducing packet availability checks (`.available()`) and tailored microsecond propagation delays to ensure the data buffer is fully populated before reading.
* **Hardware-Software Integration:** Utilized hardware serial monitoring to trace inter-MCU data flow and isolate logic bugs from physical connection issues.

## Project Structure
```text
├── Main_Controller_Uno/          # Master Node Code
│   ├── Main_Controller_Uno.ino   # Main execution loop & system setup
│   ├── DistanceSensor.h          # HC-SR04 Ultrasonic abstraction class
│   ├── BagDispenser.h            # L293D Motor control logic
│   ├── SmartScale.h              # UART Communication handler for weight data
│   └── DisplayManager.h          # ILI9341 TFT SPI Graphics abstraction
└── Weight_Sensor_ProMicro/       # Sensor Node Code
    └── Weight_Sensor_ProMicro.ino # Dedicated HX711 Load Cell reader & RF transmitter
```

## Technical Specifications
* **Languages:** C++, Arduino
* **Protocols:** SPI (Display), Wireless UART (Inter-MCU), I2C-like (HX711)
* **Components:** HC-SR04, HX711 Load Cell, L293D Motor Driver, ILI9341 TFT, RF Transceivers.
