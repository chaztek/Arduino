#include <Arduino.h>

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

int pot1pin = 0;
int val1;
int val1back;
int pot2pin = 1;
int val2;
int val2back;
int pot3pin = 2;
int val3;
int val3back;
int pot4pin = 3;
int val4;
int val4back;
int pot5pin = 4;
int val5;
int val5back;
int pot6pin = 5;
int val6;
int val6back;

void setup(){
  //  Set MIDI baud rate:
  Serial.begin(31250);



    // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
   lcd.print("Jake da snake!");
  val1 = analogRead(pot1pin);
  val1 = val1>>3;
  val2 = analogRead(pot2pin);
  analogRead(8)
  val2 = val2>>3;
  val3 = analogRead(pot3pin);
  val3 = val3>>3;
  val4 = analogRead(pot4pin);
  val4 = val4>>3;
  val5 = analogRead(pot5pin);
  val5 = val5>>3;
  val6 = analogRead(pot6pin);
  val6 = val6>>3;
  val1back = val1;
  val2back = val2;
  val3back = val3;
  val4back = val4;
  val5back = val5;
  val6back = val6;

}

void loop()
{
  val1 = analogRead(pot1pin);
  val1 = val1>>3;
  val2 = analogRead(pot2pin);
  val2 = val2>>3;
  val3 = analogRead(pot3pin);
  val3 = val3>>3;
  val4 = analogRead(pot4pin);
  val4 = val4>>3;
  val5 = analogRead(pot5pin);
  val5 = val5>>3;
  val6 = analogRead(pot6pin);
  val6 = val6>>3;
  if (val1!=val1back){
    lcd.setCursor(0, 1);
    lcd.print("pot 1");
    lcd.setCursor(6, 1);
    // print the number of seconds since reset:
    lcd.print(val1);
    delay(10);
    lcd.print("   ");
  }
  if (val2!=val2back){
    lcd.setCursor(0, 1);
    lcd.print("pot 2");
    lcd.setCursor(6, 1);
    // print the number of seconds since reset:
    lcd.print(val2);
    delay(10);
    lcd.print("   ");
  }
  /*if (val3!=val3back){
    lcd.setCursor(0, 1);
    lcd.print("pot 3");
    lcd.setCursor(4, 1);
    // print the number of seconds since reset:
    lcd.print(val3);
    delay(10);
    lcd.print("   ");
  }
  if (val4!=val4back){
    lcd.setCursor(0, 1);
    lcd.print("pot 4");
    lcd.setCursor(4, 1);
    // print the number of seconds since reset:
    lcd.print(val4);
    delay(10);
    lcd.print("   ");
  }
  if (val5!=val5back){
    lcd.setCursor(0, 1);
    lcd.print("pot 5");
    lcd.setCursor(4, 1);
    // print the number of seconds since reset:
    lcd.print(val5);
    delay(10);
    lcd.print("   ");
  }
  if (val6!=val6back){
    lcd.setCursor(0, 1);
    lcd.print("pot 6");
    lcd.setCursor(4, 1);
    // print the number of seconds since reset:
    lcd.print(val6);
    delay(10);
    lcd.print("   ");
  }*/
  // backup values for pots
  val1back = val1;
  val2back = val2;
  val3back = val3;
  val4back = val4;
  val5back = val5;
  val6back = val6;

}
