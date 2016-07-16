/* Encoder Library - 
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
  */

// this uses a mouse control to very software plugin controls

#include <CapacitiveSensor.h>

#include <Encoder.h>

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);   
// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(8, 6);
//   avoid using pins with LEDs attached
int output7 = 7;
int red =16;
int blue =19;
int green =17;
int inbut18 = 18;
boolean prevState;
long valX = 4;
long valY = -4;
long valYb = 4;
 int mode = 0;
long valXa = -4;
long val = 2;

void setup() {
//pinMode(inbut7, INPUT);
  pinMode(7, OUTPUT);          //encoder center LOW
pinMode(18, INPUT);             // switch input
pinMode(20, INPUT);            //input set for 5 volt resistor
pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
digitalWrite (output7,LOW);       //set encoder center low


}





void loop() {

 long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(200);

int mouseState=0;

 if(total1 >50){
  delay(10);
    Mouse.press();
    mouseState=Mouse.isPressed();
  }
  //if the switch attached to pin 3 is closed, release the right mouse button and save the state in a variable
  if(total1 < 50){
    delay(250);
    Mouse.release();
    //mouseState=Mouse.release();
  } 
    
    
    //delay(50);                             // arbitrary delay to limit data to serial port 


if (digitalRead(inbut18)==LOW){
  prevState=LOW;
}

if (digitalRead(18)==HIGH&&prevState==LOW){
  prevState=HIGH;
  val=val*2;
  if (val>8)
    val=2;
  if (val==2){
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
  }
  else if (val==4){
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
  }
  else if (val==8){
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
  }

long Knob = myEnc.read();
  if (Knob < 0)
     Mouse.move(valX, valY); 

 else  if (Knob > 0)
      Mouse.move(valXa,valYb);

  else 
Mouse.move(0, 0);

myEnc.write(0);
delay(5);


}  }
  

