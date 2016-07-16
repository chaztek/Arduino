/*
Chaz drum midi pads


*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define the number of samples to keep track of.  The higher the number,
// the more the readings will be smoothed, but the slower the output will
// respond to the input.  Using a constant rather than a normal variable lets
// use this value to determine the size of the readings array.
const int numReadings = 10;
int noteNum;
int readings;      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int inputPin = A0;
int highNum;
// midi shit ↓
int cmdon =0x90;

int val = 0;
long oldTime = 0;
int pad ;
int buttonState = 1;  
const int buttonPin = 8;
int lastButtonState =0;
int setoff = 0;



void setup() {
   pinMode(buttonPin, INPUT); 
 Serial.begin(31250);//....midi is 31250 
  lcd.begin(16, 2);
  // initialize the serial communications:
  lcd.print("Mr Drumps");
}


void loop() {
 buttonState = digitalRead(buttonPin);
 readings = analogRead(inputPin);
    readings = readings >> 3;
      noteNum = 40;            
      pad = 1 ;
    
  if (readings > 5) {
  setoff = 1;
   Serial.write(cmdon);
  Serial.write(noteNum);
  Serial.write(readings);
}

  if (readings > highNum){
    highNum = readings; 
     oldTime = millis();
  }
  lcd.setCursor(10, 0);
   lcd.print ("Pad-");
   lcd.print (pad);
  lcd.setCursor(0, 1);
  lcd.print("Note");
  lcd.print(" ");
  lcd.print(noteNum);
  lcd.print("  ");
  lcd.print("Vol");
 lcd.print(" ");
  lcd.print(highNum);
   lcd.print("   ");
delay(15);

 if (millis() - oldTime >500){
  highNum = readings;
 }
 
  if (setoff == 1){
  Serial.write(cmdon);
 Serial.write(noteNum);
 Serial.write(0);
setoff = 0;

  
 }
 /* if (buttonState != lastButtonState) {
    
  }
  if (buttonState == LOW) {
  Serial.write(cmdon);
  Serial.write(22);
  Serial.write(127);
  
  }
 else if (buttonState == HIGH){
  Serial.write(cmdon);
  Serial.write(22);
  Serial.write(0);
  delay(50);

 
 lastButtonState = buttonState;   
*/
}
