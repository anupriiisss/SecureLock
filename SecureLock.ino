#include <Servo.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

// Bluetooth (RX, TX)
SoftwareSerial BT(10, 11);

// LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

Servo myServo;

String password = "1234";   // Change this if needed
String input = "";

void setup() {
  BT.begin(9600);
  Serial.begin(9600);

  myServo.attach(9);
  myServo.write(0); // Locked position

  lcd.begin(16, 2);
  lcd.print("Smart Lock");
  delay(2000);
  lcd.clear();
  lcd.print("Enter Password");
}

void loop() {
  while (BT.available()) {
    char c = BT.read();
    input += c;
    delay(10);
  }

  if (input.length() > 0) {
    Serial.println(input); // Debug

    lcd.clear();

    if (input == password) {
      lcd.print("Access Granted");
      unlockDoor();
    } else {
      lcd.print("Access Denied");
    }

    delay(2000);
    lcd.clear();
    lcd.print("Enter Password");

    input = "";
  }
}

// 🔓 Unlock Function
void unlockDoor() {
  myServo.write(90); // Unlock
  delay(3000);
  myServo.write(0);  // Lock again
}
