/* Encoder Library - 
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
  */

// this uses a mouse control to very software plugin controls



#include <Encoder.h>
int      MX =  1;
int      MY =  0;
 int   MW = 0;
int delaytime = 0;
int xymove = 0;
int red =16;
int blue =19;
int green =17;
int state = 1;
int touch = 0;
// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(8,6);
//   avoid using pins with LEDs attached
int inbut18 = 18;
boolean prevState;
long val = 1;
 int mode = 0;
long  Knob = 0;
int output7 = 7;
long touchme = 0;
long intouch = 0;
void setup() {

 
 // pinMode(8, INPUT);
 // pinMode(6, INPUT);
 pinMode(25, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(7, OUTPUT);
pinMode(18, INPUT);
pinMode(20, INPUT);
pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
digitalWrite (output7,LOW);
digitalWrite (25,LOW);
digitalWrite (4,LOW);
Serial.begin(57600);
delay(500);
long touchme = touchRead(3);
 
intouch = touchme +1000;
 Mouse.end();

 state=8;
}

void loop() {
 Mouse.end();
long Knob = myEnc.read();

if (digitalRead(inbut18)==LOW){
  prevState=LOW;

}
if (digitalRead(18)==HIGH&&prevState==LOW){
  prevState=HIGH;
  state=state*2;
  if (state>8)
    state=2;
}

    if (state==2){
    digitalWrite(red, HIGH);
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
        MX =  3;
      MY =  0;
     MW = 0;
  }
  else if (state==4){
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
         MX =  0;
      MY =  16;
     MW = 0;
  }
  else if (state==8){
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(green, HIGH);
      MX =  0;
      MY =  0;
     MW = 1;
  }

  

long touchme = touchRead(3);


if (touchme > intouch){      //calibration
touch = +1;


//delay(20);
  //Mouse.press();
}
 else if (touchme < intouch){      //calibration
    touch = -1;
   //Mouse.release();
//Mouse.end();
 }

 if (state != 8){
  if(touch > 0){
 Mouse.begin();
delay(2);
  Mouse.press();
 }}

// long Knob = myEnc.read();
//digitalWrite (output7,LOW);


 
  if (Knob < 0){
   Mouse.move(MX*val, -MY*val, MW*val);            //was -- Mouse.move(val, val); 
     //xymove=xymove+val;
  }
 else  if (Knob > 0){
     Mouse.move(-MX*val, MY*val, -MW*val);     //Mouse.move(-val,val,);    
    // xymove=xymove-val;
     Mouse.move(0, 0 ,0);
 
 
 }
  if (touch < 0){
    delay(100);
 Mouse.release();
//digitalWrite (output7,HIGH);
Mouse.move(val/2, val/2 ,val/2);

  } 
  else{
 Mouse.move(0, 0 ,0);
Mouse.end();
  }
{
myEnc.write(0);
delay(5);
}

//if (Serial.read = (0))
//void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers



  //Mouse.move(-xymove/2,xymove/2,xymove/2,xymove/2);
  //Mouse.move(xymove,xymove,xymove);
 //xymove=0;
  //Mouse.end();
{
 Serial.println(intouch);
  Serial.println(touchme);
  Serial.println(touch);
}}


  

