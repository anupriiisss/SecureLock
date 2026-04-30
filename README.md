# SecureLock
This project implements a Bluetooth-based smart door lock system using an Arduino Uno. The system allows a user to enter a password via a mobile application, which is transmitted wirelessly using a Bluetooth module. Based on password verification, a servo motor controls the locking and unlocking mechanism, while the LCD provides real-time system feedback.

Bluetooth-based smart lock using Arduino, servo motor, and LCD.

## Components
- Arduino Uno
- HC-05 Bluetooth Module
- LCD
- Servo Motor

## Working
User sends password via Bluetooth → Arduino verifies → Servo unlocks if correct.

## How to Run
Upload code → Connect components → Pair Bluetooth → Send password
