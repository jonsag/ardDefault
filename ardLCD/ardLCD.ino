/*
  The LCD circuit:
                               GND            display pin 1
    supply voltage for logic   +5V            display pin 2

   10K potentiometer:
   ends to +5V and ground
   LCD VO - contrast           wiper          display pin 3

   LCD RS pin                  digital pin 13 display pin 4
   LCD R/W pin                 GND            display pin 5
   LCD Enable pin              digital pin 12 display pin 6
   LCD D4                      digital pin 11 display pin 11
   LCD D5                      digital pin 10 display pin 12
   LCD D6                      digital pin 9  display pin 13
   LCD D7                      digital pin 8  display pin 14

   220ohm resistor to +5V
   back light anode:+4.2V      220ohm         display pin 15
   back light cathode          GND	          display pin 16
*/

String programName = "ardLCD";
String date = "201910013";
String author = "Jon Sagebrand";
String email = "jonsagebrand@gmail.com";

/*******************************
 * LCD setup
 *******************************/
// include the LCD library
#include <LiquidCrystal.h>
// set LCD pins
const int LCD_RS = 13; // LCD RS, pin 4
const int LCD_EN = 12; // LCD E, pin 6, Enable
const int LCD_D4 = 11; // LCD D4, pin 11, databit 4
const int LCD_D5 = 10; // LCD D5, pin 12, databit 5
const int LCD_D6 = 9; // LCD D6, pin 13, databit 6
const int LCD_D7 = 8; // LCD D7, pin 14, databit7
/* other pins on LCD are:
 * VSS, pin 1, GND
 * VDD, pin 2, +5V
 * V0, pin 3, 10k potentiometer, ends to +5V and GND, middle pin to V0, contrast
 * R/W, pin 5, GND, Read/Write
 * A, pin 15, 220ohm resistor, one end to +5V, other to A, back light anode, ~+4.2V
 * K, pin 16, GND, back light cathode
 * D0, pin 7, databit 0, not used/connected
 * D1, pin 8, databit 1, not used/connected
 * D2, pin 9, databit 2, not used/connected
 * D3, pin 10, databit 3, not used/connected
 */
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(&LCD_RS, &LCD_EN, &LCD_D4, &LCD_D5, &LCD_D6, &LCD_D7);
// columns and rows of the LCD
int lcdColumns = 16;
int lcdRows = 2;

void setup(void) {

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

  lcd.clear();
}

void loop(void) {
	lcd.setCursor(0, 0);
	lcd.print("Hello world");
	lcd.setCursor(0, 1);
	lcd.print(millis() / 1000); // prints how many seconds this program has run
}

