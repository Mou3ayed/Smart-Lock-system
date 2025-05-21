# Smart-Lock-system
Smart Lock System using Arduino, Keypad, LCD, Servo, and Buzzer. A password-protected door lock simulation with feedback on an LCD and alert sound on wrong attempts
🔐 Arduino Smart Lock System
This is a Smart Lock System built with Arduino Uno that uses a 4x4 Keypad, 16x2 LCD, Servo Motor, and Buzzer to simulate a secure password-based door lock. This project is perfect for beginners learning about Arduino, electronics, and embedded systems.

📌 Features
✅ 4-digit password entry via Keypad

✅ Visual feedback with a 16x2 LCD screen

✅ Servo motor acts as door lock mechanism

✅ Buzzer alerts on incorrect password attempts

✅ LCD shows real-time input and system messages

✅ Reset input with *, submit password with #

🧰 Components Used
Arduino Uno

4x4 Keypad

16x2 LCD Display (non-I2C)

10kΩ Potentiometer (for LCD contrast)

SG90 Servo Motor

Piezo Buzzer

Breadboard & Jumper Wires

🔌 Circuit Diagram
All connections are clearly described in the code comments. The LCD uses digital pins 2–5, 11, 12, and the keypad is connected to pins 6–9 (rows) and A0–A3 (columns). The servo connects to A5, and the buzzer to pin 10.

🧠 How It Works
Start the system – LCD prompts for password.

Enter the password using the keypad.

If correct, the servo unlocks the “door” for 5 seconds.

If incorrect, the buzzer sounds an alert 3 times.

Press * to reset/clear input.

💻 Code
Written in C++ using Arduino IDE, this code uses:

LiquidCrystal library for LCD

Keypad library for user input

Servo library for lock control

tone() for buzzer alerts
![Smart Lock Setup](smart-lock-setup.png)

