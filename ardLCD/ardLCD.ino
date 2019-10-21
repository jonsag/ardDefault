String programName = "ardLCD";
String date = "201910013";
String author = "Jon Sagebrand";
String email = "jonsagebrand@gmail.com";

/*******************************
  LCD setup
 *******************************/
#include <LiquidCrystal.h> // include the LCD library

// define LCD pins
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

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7); // initialize the library with the numbers of the interface pins

int lcdColumns = 16; // set columns and rows of the LCD
int lcdRows = 2;

/*******************************
  set up misc variables
 *******************************/
int uptime;

void setup(void) {
  /*******************************
    start LCD
   *******************************/
  lcd.begin(lcdColumns, lcdRows);

  lcd.setCursor(0, 0); // print name of this program and boot message to the LCD
  lcd.print(programName);
  lcd.setCursor(0, 1);
  lcd.print("Booting ...");

  /*******************************
    start serial
   *******************************/
  lcd.setCursor(0, 1);
  lcd.print("Starting serial ...");
  Serial.begin(9600); // start serial port

  Serial.println(programName); // print information
  Serial.println(date);
  Serial.print("by ");
  Serial.print(author);
  Serial.println(email);
  Serial.println();

  /*******************************
    start
   *******************************/
  Serial.println("Starting ...");
  Serial.println();
  lcd.clear();
}

void loop(void) {
  lcd.setCursor(0, 0);
  lcd.print("Hello world");

  uptime = millis() / 1000; //how many seconds this program has run

  lcd.setCursor(0, 1);
  lcd.print(uptime);

  Serial.println(uptime);
}
