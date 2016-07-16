/* Encoder Library - 
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
  */

// this uses a mouse control to very software plugin controls



#include <Encoder.h>
long touchON = 0;
long touchOFF = 0;
int delaytime = 0;
int xymove = 0;
int red =16;
int blue =19;
int green =17;
long touchy =0;
int butthole =0;
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

int output7 = 7;
long touchme;

void setup() {
 
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
pinMode(18, INPUT);
pinMode(20, INPUT);
pinMode(25, OUTPUT);
pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
digitalWrite (output7,LOW);
digitalWrite (4,LOW);
digitalWrite (25,LOW);
}

void loop() {

digitalWrite (output7,LOW);

if (digitalRead(inbut18)==LOW){
  prevState=LOW;
}

if (digitalRead(18)==HIGH&&prevState==LOW){
  prevState=HIGH;
  butthole= (butthole+1);
 if (butthole>3){
    butthole=1;

 } 
}
  if (butthole==1){
    digitalWrite(red, HIGH);
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
 
  }
  else if (butthole==2){
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
  val=val*2;
    
  }
  else if (butthole==3){
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(green, HIGH);
 val=val*4;
  }
  


touchme = touchRead(3);
//Serial.println(touchme);

if (touchme > 2500){
touchy = +1;
}

  else if (touchme < 2200){
   touchy = -1;
   delay(100);
  }
//Serial.println (touchy);

  

 if(touchy > 0){
 Mouse.press();
 long Knob = myEnc.read();
  if (Knob < 0){
     Mouse.move(val, -val); 
     xymove=xymove+val;
  }

 else  if (Knob > 0){
      Mouse.move(-val,val);    
     xymove=xymove-val;
 }
  else 
Mouse.move(0, 0);

myEnc.write(0);
delay(5);
 }
  else if (touchy < 0){
  Mouse.release();
  
Mouse.move(-xymove/2,xymove/2);
 xymove=0;
 touchy=0;
 val=1;
  }
Mouse.move(0,0);
 }
  //Serial.println(touchme);
  //Serial.println();
  //Serial.println(touchOFF);

  

