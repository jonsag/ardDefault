

String programName = "ardLCD";
String date = "201910013";
String author = "Jon Sagebrand";
String email = "jonsagebrand@gmail.com";

/*******************************
 * Stepper motor setup
 *******************************/
#include <Stepper.h> // include the Stepper library
#define STEPS 32 // change this to the number of steps on your motor
// set stepper pins
int stepperIN1 = 8;
int stepperIN2 = 9;
int stepperIN3 = 10;
int stepperIN4 = 11;
// create an instance of the stepper class using the steps and pins
Stepper stepper(STEPS, stepperIN1, stepperIN2, stepperIN3, stepperIN4);

/*******************************
 * LCD setup
 *******************************/
#include <LiquidCrystal.h> // include the LCD library
// set LCD pins
int LCD_RS = 2; // LCD RS, pin 4
int LCD_EN = 3; // LCD E, pin 6, Enable
int LCD_D4 = 4; // LCD D4, pin 11, databit 4
int LCD_D5 = 5; // LCD D5, pin 12, databit 5
int LCD_D6 = 6; // LCD D6, pin 13, databit 6
int LCD_D7 = 7; // LCD D7, pin 14, databit7
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
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
// columns and rows of the LCD
int lcdColumns = 16;
int lcdRows = 2;

/*******************************
 * Misc variables setup
 *******************************/
int val = 0;

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

  // initialize stepper
  lcd.setCursor(0, 1);
  lcd.print("Starting stepper ...");
  Serial.println("Starting stepper ...");
  Serial.println();
  stepper.setSpeed(500);

  lcd.clear();
}

void loop(void) {
	lcd.setCursor(0, 0);
	lcd.print("Hello world");
  
  // read serial
  if (Serial.available()>0) {
      val = Serial.parseInt();
      stepper.step(val);
      Serial.println(val); //for debugging
    }
}
