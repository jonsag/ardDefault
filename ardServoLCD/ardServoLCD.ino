String programName = "ardServoLCD";
String date = "201910013";
String author = "Jon Sagebrand";
String email = "jonsagebrand@gmail.com";

/*******************************
   LCD setup
 *******************************/
// include the LCD library
#include <LiquidCrystal.h>
// set LCD pins
int LCD_RS = 2; // LCD RS, pin 4
int LCD_EN = 3; // LCD E, pin 6, Enable
int LCD_D4 = 4; // LCD D4, pin 11, databit 4
int LCD_D5 = 5; // LCD D5, pin 12, databit 5
int LCD_D6 = 6; // LCD D6, pin 13, databit 6
int LCD_D7 = 7; // LCD D7, pin 14, databit7
/* other pins on LCD are:
   VSS, pin 1, GND
   VDD, pin 2, +5V
   V0, pin 3, 10k potentiometer, ends to +5V and GND, middle pin to V0, contrast
   R/W, pin 5, GND, Read/Write
   A, pin 15, 220ohm resistor, one end to +5V, other to A, back light anode, ~+4.2V
   K, pin 16, GND, back light cathode
   D0, pin 7, databit 0, not used/connected
   D1, pin 8, databit 1, not used/connected
   D2, pin 9, databit 2, not used/connected
   D3, pin 10, databit 3, not used/connected
*/
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
// columns and rows of the LCD
int lcdColumns = 16;
int lcdRows = 2;

/*******************************
   Servo setup
 *******************************/
// include the Servo library
#include <Servo.h>
Servo myservo;  // create servo object to control a servo

/*******************************
   Pin setup
 *******************************/
int potpin = 3;  // analog pin used to connect the potentiometer
int servoPin = 9; // pin the servo is connectod to

/*******************************
   Misc variables
 *******************************/
int val;    // variable to read the value from the analog pin
int valLength; // stores number of digits in int
String valString; // stores int coverted to string

void setup() {
  // start LCD
  lcd.begin(lcdColumns, lcdRows);
  // print name of this program and boot message to the LCD
  lcd.setCursor(0, 0);
  lcd.print(programName);
  lcd.setCursor(0, 1);
  lcd.print("Booting ...");

  // start serial port
  lcd.setCursor(0, 1);
  lcd.print("Starting serial ...");
  Serial.begin(9600);

  // print information
  Serial.println(programName);
  Serial.println(date);
  Serial.print("by ");
  Serial.print(author);
  Serial.println(email);
  Serial.println();

  // initiate servo
  lcd.setCursor(0, 1);
  lcd.print("Starting servo ...");
  Serial.println("Starting servo ...");
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object

  lcd.clear();
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)

  // print val to LCD
  lcd.setCursor(0, 0);
  lcd.print("Pot val: ");
  lcd.setCursor(9, 0);
  lcd.print(val);
  valLength = intToStringToLength(val);
  lcd.setCursor(9 + valLength, 0);
  lcd.print("   ");
  // print val to serial
  Serial.print("Pot val: ");
  Serial.print(val);

  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)

  // print val to LCD
  lcd.setCursor(0, 1);
  lcd.print("Servo val: ");
  lcd.setCursor(11, 1);
  lcd.print(val);
  valLength = intToStringToLength(val);
  lcd.setCursor(11 + valLength, 1);
  lcd.print((char)223); // prints degree sign
  lcd.setCursor(11 + valLength + 1, 1);
  lcd.print("  ");
  // print val to serial
  Serial.print(", Servo val: ");
  Serial.println(val);

  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}

int intToStringToLength(int val) { // returns how many numbers in integer
  valString = String(val);
  valLength = valString.length();
  return valLength;
}
