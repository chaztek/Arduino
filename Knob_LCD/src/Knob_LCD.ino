/*
  LiquidCrystal Library - Serial Input
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch displays text sent over the serial port 
 (e.g. from the Serial Monitor) on an attached LCD.
 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe 
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/LiquidCrystalSerial
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pot1pin = 0;  // analog pin used to connect the potentiometer
int val1;    // variable to read the value from the analog pin 
int val1back;
int val1av;
int allowance=1;\
int thresh[2] = {1, 1,};
// midi values
int cmd = 0xb0;
int ccnumb1 = 0x07;
int ccnumb2 = 0x08;
int ccvolume = 0x00;



void setup(){
   //  Set MIDI baud rate:
  Serial.begin(31250);
    // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // initialize the serial communications:
   lcd.print("hello, Jake!");
}

void loop()
{
     // reads the value of the potentiometer (value between 0 and 1023)
      val1 = analogRead(pot1pin);   
       val1back = val1;
       val1av = val1-allowance-1;
  //val = map(val, 0, 1023, 0, 722); 
    val1 = val1 >> 3 ;
   if (val1 != val1back && (val1+allowance != val1av || val1-allowance != val1av)) {
   
   // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
 lcd.setCursor(2, 1);
 lcd.print("pot 1 ");
  lcd.setCursor(8, 1);
  lcd.print(val1);
  delay(25);
  lcd.print("   ");  
   
//val1av=val1;
     if  (val1back != val1){
  Serial.write(cmd);
  Serial.write(ccnumb1);
  Serial.write(val1);
  val1back=val1;
    }  

}}
