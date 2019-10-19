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
int inputPotPin = 3;  // analog pin used to connect the potentiometer
int processValuePotPin = 2 ; // analog pin to recieve process value from potentiometer attached to LCD
int servoPin = 9; // pin the servo is connectod to

/*******************************
   Misc variables
 *******************************/
int SPt; // variable to read the value from the analog pin, Set Point
int SVa; // variable to store the Servo Value
int PVa; // input from potentiometer attached to servo, Process Value

int valLength; // stores integer to count length of
String valString; // stores integer coverted to string

int Xoffset; // how far out the LCD should it be printed
int Yline; // what line should message be printed at
int totLength; // total length of text + digits to LCD
int noOfChars; // number of digits in integer
int noOfDigits; // number of characters in string

/*******************************
   Text variables
 *******************************/
String SPtText = "SP:";
String SVaText = "SV:";
String PVaText = "PV:";

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
  SPt = analogRead(inputPotPin);            // SetPoint, reads the value of the potentiometer (value between 0 and 1023)
  PVa = analogRead(processValuePotPin);            // ProcessValue, reads the value of the potentiometer (value between 0 and 1023)
  
  // print set point to LCD
  Xoffset = 0;
  Yline = 0;
  lcd.setCursor(Xoffset, Yline);
  lcd.print(SPtText);
  noOfChars = SPtText.length(); // number of characters before digits
  lcd.setCursor(Xoffset + noOfChars, Yline);
  lcd.print(SPt);
  noOfDigits = intToStringToLength(SPt);
  totLength = noOfChars + noOfDigits;
  lcd.setCursor(Xoffset + totLength, Yline);
  lcd.print("   ");
  // print to serial
  Serial.print("Set Point: ");
  Serial.print(SPt);
  Serial.print(", No of digits:");
  Serial.print(noOfDigits);

  SVa = map(SPt, 0, 1023, 0, 180);     // ServoValue, scale it to use it with the servo (value between 0 and 180)

  // print servo value to LCD
  Xoffset = 9;
  Yline = 0;
  lcd.setCursor(Xoffset, Yline);
  lcd.print(SVaText);
  noOfChars = SVaText.length(); // number of characters before digits
  lcd.setCursor(Xoffset + noOfChars, Yline);
  lcd.print(SVa);
  noOfDigits = intToStringToLength(SVa);
  totLength = noOfChars + noOfDigits;
  lcd.setCursor(Xoffset + totLength, Yline);
  lcd.print((char)223); // prints degree sign
  lcd.setCursor(Xoffset + totLength + 1, Yline);
  lcd.print("  ");
  // print to serial
  Serial.print(", Servo value: ");
  Serial.print(SVa);
  Serial.print(", No of digits:");
  Serial.print(noOfDigits);
  Serial.println();

  // print process value to LCD
  Xoffset = 0;
  Yline = 1;
  lcd.setCursor(Xoffset, Yline);
  lcd.print(PVaText);
  noOfChars = PVaText.length(); // number of characters before digits
  lcd.setCursor(Xoffset + noOfChars, Yline);
  lcd.print(PVa);
  noOfDigits = intToStringToLength(PVa);
  totLength = noOfChars + noOfDigits;
  lcd.setCursor(Xoffset + totLength, Yline);
  lcd.print("   ");
  // print to serial
  Serial.print("Set Point: ");
  Serial.print(PVa);
  Serial.print(", No of digits:");
  Serial.print(noOfDigits);
  
  myservo.write(SVa);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}

int intToStringToLength(int valInt) { // returns how many numbers in integer
  valString = String(valInt);
  valLength = valString.length();
  return valLength;
}

int doubleToStringToLength(float valDouble) { // returns how many numbers in integer
  int valInt = valDouble * 10;
  valString = String(valInt);
  valLength = valString.length() + 1;
  return valLength;
}
