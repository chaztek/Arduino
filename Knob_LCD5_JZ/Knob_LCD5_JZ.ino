/*


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
int val1av;
int pot2pin = 1;
int val2;
int val2back;
int val2av;
int pot3pin = 2;
int val3;
int val3back;
int val3av;
int pot4pin = 3;
int val4;
int val4back;
int val4av;
int pot5pin = 4;
int val5;
int val5back;
int val5av;
int pot6pin = 5;
int val6;
int val6back;
int val6av;
//allowance
int allowance=1;
// midi values
int cmd = 0xb0;
int ccnumb1 = 0x07;
int ccnumb2 = 0x08;
int ccvolume = 0x00;
int thresh[2] = {1, 1,};



void setup() {
  //  Set MIDI baud rate:
  Serial.begin(31250);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
  lcd.print("Jake da snake!");
  val1 = analogRead(pot1pin);
  val1 = val1 >> 3;
  val2 = analogRead(pot2pin);
  val2 = val2 >> 3;
  val3 = analogRead(pot3pin);
  val3 = val3 >> 3;
  val4 = analogRead(pot4pin);
  val4 = val4 >> 3;
  val5 = analogRead(pot5pin);
  val5 = val5 >> 3;
  val6 = analogRead(pot6pin);
  val6 = val6 >> 3;
  
  val1back = val1;
  val2back = val2;
  val3back = val3;
  val4back = val4;
  val5back = val5;
  val6back = val6;
  
  val1av = val1-allowance-1;
  val2av = val2-allowance-1;
  val3av = val3-allowance-1;
  val4av = val4-allowance-1;
  val5av = val5-allowance-1;
  val6av = val6-allowance-1;
}





void loop()
{
  
  val1 = analogRead(pot1pin);
  val1 = val1 >> 3;
  val2 = analogRead(pot2pin);
  val2 = val2 >> 3;
  val3 = analogRead(pot3pin);
  val3 = val3 >> 3;
  val4 = analogRead(pot4pin);
  val4 = val4 >> 3;
  val5 = analogRead(pot5pin);
  val5 = val5 >> 3;
  val6 = analogRead(pot6pin);
  val6 = val6 >> 3;
  // check if value is greater than defined threshold (good for resistive touchpads etc)
  //if (val1 >thresh ){
  if (val1 != val1back && (val1+allowance != val1av || val1-allowance != val1av)) {
    lcd.setCursor(0, 1);
    lcd.print("pot 1");
    lcd.setCursor(6, 1);

    lcd.print(val1);
    delay(10);
    lcd.print("   ");
    
    val1av=val1;
    
    Serial.write(cmd);
    Serial.write(ccnumb1);
    Serial.write(val1);
  }
  // if (val2! >thresh ){

  if (val2 != val2back && (val2+allowance != val2av || val2-allowance != val2av)) {
    lcd.setCursor(0, 1);
    lcd.print("pot 2");
    lcd.setCursor(6, 1);

    lcd.print(val2);
    delay(10);
    lcd.print("   ");
    
    val1av=val1;
    
    Serial.write(cmd);
    Serial.write(ccnumb2);
    Serial.write(val2);
  }
  
  //I REMOVED ALL THE EXTRA STUFF... WE CAN COPY IT BACK IN LATER
  
  //store average values
  
  
  // backup values for pots
  val1back = val1;
  val2back = val2;
  val3back = val3;
  val4back = val4;
  val5back = val5;
  val6back = val6;
  
  

}
