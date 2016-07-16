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


void setup() {

 
 // pinMode(8, INPUT);
 // pinMode(6, INPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
pinMode(18, INPUT);
pinMode(20, INPUT);
pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
digitalWrite (output7,LOW);
digitalWrite (4,LOW);
//Serial.begin(9600);
// Mouse.begin();
}

void loop() {
 
digitalWrite (output7,LOW);
//digitalWrite (4,LOW);
long Knob = myEnc.read();

if (digitalRead(inbut18)==LOW){
  prevState=LOW;
}

if (digitalRead(18)==HIGH&&prevState==LOW){
  prevState=HIGH;
  val=val*2;
  if (val>8)
    val=2;


    if (val==2){
    digitalWrite(red, HIGH);
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
        MX =  1;
      MY =  0;
     MW = 0;
  }
  else if (val==4){
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
         MX =  0;
      MY =  1;
     MW = 0;
  }
  else if (val==8){
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(green, HIGH);
      MX =  0;
      MY =  0;
     MW = 1;
  }
}
  



//long touchme = touchRead(3);


//if (touchme > 2110){
//touchme = +1;


//delay(20);
  //Mouse.press();

 // else if (touchme < 2110){
    //touchme = -1;
   
//Mouse.release();


 //if(touchme > 0){
 //Mouse.press();
// long Knob = myEnc.read();
  if (Knob < 0)
   Mouse.move(MX*val, MY*val, MW*val);            //was -- Mouse.move(val, val); 
     
 
    // xymove=xymove+val;


 else  if (Knob > 0)
     Mouse.move(-MX*val, -MY*val, -MW*val);     //Mouse.move(-val,val,);    
     // xymove=xymove-val;

 
 
  else
  Mouse.move(0, 0 ,0);


myEnc.write(0);
delay(5);

  //else if (touchme < 0){
 // Mouse.release();
  //Mouse.move(-xymove/2,xymove/2);
  //Mouse.move(xymove,xymove);
 //xymove=0;
 
  //Serial.println(touchme);

}
  

