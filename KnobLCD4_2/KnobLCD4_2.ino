/*


 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/LiquidCrystalSerial
 */
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pot1pin = 0;
int val1;
int val1back;
int val1av[10];
int pot2pin = 1;
int val2;
int val2back;
int val2av[10];

//cycles before storage for averaging
int cycles=25;
int count=0;
int allowance=1;

int valueback =200;

int choice=0;
// midi values
int cmd = 0xb0;
int ccnumb1 = 0x07;
int ccnumb2 = 0x08;
int ccvolume = 0x00;
int thresh[2] = {1, 1,};

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
    // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
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

  
  val1back = val1;
  val2back = val2;

  
  
}


int sum(int y[]){
  int sums=0;
  for (int i=0; i<10; i++){
    sums=sums+y[i];
  }
  return sums;
}


void outPutter(String name, int value, int ccnumb){
  lcd.setCursor(0, 1);
  lcd.print(name);
  lcd.setCursor(6, 1);

  lcd.print(value);
  delay(10);
  lcd.print("   ");
    
   // if  (valueback != value){
  Serial.write(cmd);
  Serial.write(ccnumb);
  Serial.write(value);
 // valueback=value;
    }
}
 
void loop()
{
  
  
  val1 = analogRead(pot1pin);
  val1 = val1 >> 3;
  val2 = analogRead(pot2pin);
  val2 = val2 >> 3;

  // check if value is greater than defined threshold (good for resistive touchpads etc)
  //if (val1 >thresh ){
  if (val1 != val1back && abs(val1-val1back)>1)
    choice=1;
  if (val2 != val2back && abs(val2-val2back)>1)
    choice=2;
    
    
  if (choice==1) {
    outPutter("pot1", sum(val1av)/10, ccnumb1);
  }
  // if (val2! >thresh ){

  if (choice==2) {
    outPutter("pot2", sum(val2av)/10, ccnumb2);
  }
  
  //I REMOVED ALL THE EXTRA STUFF... WE CAN COPY IT BACK IN LATER
  
  //store average values
  
  
  // backup values for pots
  val1back = val1;
  val2back = val2;

  val1av[count]=val1;
  val2av[count]=val2;
  
  if (count==9){
    count=-1;
  }
  count++;
  

}
