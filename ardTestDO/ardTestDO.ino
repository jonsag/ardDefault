

String programName = "ardTestDO";
String date = "201910014";
String author = "Jon Sagebrand";
String email = "jonsagebrand@gmail.com";

// define pins
int DO2 = 2;
int DO3 = 3;
int DO4 = 4;
int DO5 = 5;
int DO6 = 6;
int DO7 = 7;
int DO8 = 8;
int DO9 = 9;
int DO10 = 10;
int DO11 = 11;
int DO12 = 12;
int DO13 = 13;

// times
int onTime = 900;
int offTime = 100;

void setup(void) {

  // start serial port
  Serial.begin(9600);

  // print information
  Serial.println(programName);
  Serial.println(date);
  Serial.print("by ");
  Serial.print(author);
  Serial.println(email);
  Serial.println();

  // setup pins
  Serial.println("Setting up pins ...");
  pinMode(DO2, OUTPUT);
  pinMode(DO3, OUTPUT);
  pinMode(DO4, OUTPUT);
  pinMode(DO5, OUTPUT);
  pinMode(DO6, OUTPUT);
  pinMode(DO7, OUTPUT);
  pinMode(DO8, OUTPUT);
  pinMode(DO9, OUTPUT);
  pinMode(DO10, OUTPUT);
  pinMode(DO11, OUTPUT);
  pinMode(DO12, OUTPUT);
  pinMode(DO13, OUTPUT);
}


void loop(void) {
  digitalWrite(DO2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(DO3, HIGH);
  digitalWrite(DO4, HIGH);
  digitalWrite(DO5, HIGH);
  digitalWrite(DO6, HIGH);
  digitalWrite(DO7, HIGH);
  digitalWrite(DO8, HIGH);
  digitalWrite(DO9, HIGH);
  digitalWrite(DO10, HIGH);
  digitalWrite(DO11, HIGH);
  digitalWrite(DO12, HIGH);
  digitalWrite(DO13, HIGH);
  delay(onTime);                       // wait
  
  digitalWrite(DO2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(DO3, LOW);
  digitalWrite(DO4, LOW);
  digitalWrite(DO5, LOW);
  digitalWrite(DO6, LOW);
  digitalWrite(DO7, LOW);
  digitalWrite(DO8, LOW);
  digitalWrite(DO9, LOW);
  digitalWrite(DO10, LOW);
  digitalWrite(DO11, LOW);
  digitalWrite(DO12, LOW);
  digitalWrite(DO13, LOW);
  delay(offTime);                       // wait
}
