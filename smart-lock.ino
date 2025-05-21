#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal.h>

// Initialize the LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Servo lockServo;
const int buzzerPin = 10;

String password = "1234";
String input = "";

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {A3, A2, A1, A0};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Enter Password:");

  lockServo.attach(A5);
  lockServo.write(0); // Locked position

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') {
      if (input == password) {
        lcd.clear();
        lcd.print("Access Granted");
        unlockDoor();
      } else {
        lcd.clear();
        lcd.print("Access Denied");
        errorBeep();
      }
      delay(2000);
      lcd.clear();
      lcd.print("Enter Password:");
      input = "";
    } else if (key == '*') {
      input = "";
      lcd.clear();
      lcd.print("Input Cleared");
      delay(1000);
      lcd.clear();
      lcd.print("Enter Password:");
    } else {
      input += key;
      lcd.setCursor(0, 1);
      lcd.print(input);
    }
  }
}

void unlockDoor() {
  lockServo.write(90); // Unlock
  delay(5000);
  lockServo.write(0);  // Lock again
  lcd.clear();
  lcd.print(" Locked");
  delay(1000);
}

void errorBeep() {
  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, 500);
    delay(150);
    noTone(buzzerPin);
    delay(100);
  }
}


