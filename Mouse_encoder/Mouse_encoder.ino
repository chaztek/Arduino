/* Encoder Library - 
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
  */

// this uses a mouse control to very software plugin controls

#include <CapacitiveSensor.h>

#include <Encoder.h>

CapacitiveSensor   cs_4_23 = CapacitiveSensor(4,23);   
// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(2, 3);
//   avoid using pins with LEDs attached
int inbut7 = 7;
long valX = 1;
long valY = -1;
long valXa = -1;
long valYb = 1;
 int mode = 0;
String button1;

void setup() {
pinMode(inbut7, INPUT);
  Mouse.begin();
}

void loop() {

 long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(200);

int mouseState=0;

 if(total1 >50){
    Mouse.press();
    mouseState=Mouse.isPressed();
  }
  //if the switch attached to pin 3 is closed, release the right mouse button and save the state in a variable
  if(total1 < 50){
    Mouse.release();
    mouseState=Mouse.isPressed();
  } 
    
    
    //delay(50);                             // arbitrary delay to limit data to serial port 


button1 = digitalRead(inbut7);
{
if (button1==HIGH){
mode =  +1;
}
else  (mode = 0);
 valX = 1;
 valY = -1;
 valXa = -1;
 valYb = 1;
}
{
if (mode = 1)
 valX = 4;
 valY = -4;
 valXa = -4;
 valYb = 4;
}
{
 if (mode = 2)
 valX = 8;
 valY = -8;
 valXa = -8;
 valYb = 8;
}
{
 if (mode = 3);
mode = 0;
}
{
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
  

