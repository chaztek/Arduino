/*


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

boolean buttonP=false;
const int numReadings = 10;

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
// midi values
int cmd = 0xb0;
int cmdon =0x90;
int cmdoff = 0x80;
int ccnumb1 = 0x01;
int ccnumb2 = 0x02;
int ccvolume = 0x00;
int thresh[2] = {1, 1,};
int note60 = 0x3C;
int note61 = 0x3D;
int val0 = 0x00;
int rate = (32000);
int val = 0;

void setup() {
  //  Set MIDI baud rate:
  Serial.begin(31250);//....midi is 31250

pinMode(8,INPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
  lcd.print("Mr Sample Tester");
  val1 = analogRead(pot1pin);
  //val1 = val1 >> 3;
  val2 = analogRead(pot2pin);
  //val2 = val2 >> 3;
  /*val3 = analogRead(pot3pin);
  val3 = val3 >> 3;
  val4 = analogRead(pot4pin);
  val4 = val4 >> 3;
  val5 = analogRead(pot5pin);
  val5 = val5 >> 3;
  val6 = analogRead(pot6pin);
  val6 = val6 >> 3;
  */
  val1back = val1;
  val2back = val2;
  val3back = val3;
  val4back = val4;
  val5back = val5;
  val6back = val6;
  // select threshold for each analog input


}

void loop()
{
  val1 = analogRead(pot1pin);
  //val1 = val1 >> 3;
  val2 = analogRead(pot2pin);
 // val2 = val2 >> 3;
 /* val3 = analogRead(pot3pin);
  val3 = val3 >> 3;
  val4 = analogRead(pot4pin);
  val4 = val4 >> 3;
  val5 = analogRead(pot5pin);
  val5 = val5 >> 3;
  val6 = analogRead(pot6pin);
  val6 = val6 >> 3;
  // check if value is greater than defined threshold (good for resistive touchpads etc)
  //if (val1 >thresh ){
  */
  //if (val2 != val2back) {
    lcd.setCursor(0, 1);
    lcd.print("Midi vel ");
    lcd.print("");
    lcd.print(" ");
    lcd.print(val2);
    delay(10);
    lcd.print("   ");
 /*   
    //midiout ↓
switch  (digitalRead(8)==LOW) {
  delay(50);
  Serial.write(cmdon);
  Serial.write(note60);
  Serial.write(val2);
break;
 

 switch (digitalRead(8)==HIGH) 
  Serial.write(cmdoff);
  Serial.write(note60);
  Serial.write(val2);
  break;
  } */
  {
   if (digitalRead(7) == LOW){
      Serial.write(cmdon);
  Serial.write(note60);
  Serial.write(val2);
  
 while (digitalRead(7) == LOW);
  }


   
   if (digitalRead(8) == LOW){
      Serial.write(cmdon);
  Serial.write(note61);
  Serial.write(val2);
  
 while (digitalRead(8) == LOW);
  }
  

 if (digitalRead(8) == HIGH && digitalRead(7) == HIGH){
     Serial.write(cmdoff);
  Serial.write(note60);
  Serial.write(val0);
       
   while (digitalRead(7) == HIGH && digitalRead(8)==HIGH){
 
      val2 = analogRead(pot2pin);
 //val2 = val2 >>3;
val2 = map(val2, 0,1023, 0, 360 );
val2 = constrain(val2, 0, 127);
// limits range of sensor values to between 0 and 127
   lcd.setCursor(0, 1);
    lcd.print("Midi val ");
    lcd.print("");
    lcd.print(" ");
    lcd.print(val2);
    delay(10);
    lcd.print("   ");
       
 
 
    //Serial.begin(356 * val2);
 // Serial.write(cmdon);
 // Serial.write(note61);
 // Serial.write(val2);

   }
    //lcd.print("OFF");
 
  }}}
