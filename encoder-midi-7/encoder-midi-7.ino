/* Encoder Library - 
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
  */

// this uses a mouse control to very software plugin controls


#include <MIDI.h>
#include <Encoder.h>
long touchON = 0;
long touchOFF = 0;
int delaytime = 0;
int xymove = 0;
int red =16;
int blue =19;
int green =17;

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(6,8);
//   avoid using pins with LEDs attached
int inbut18 = 18;
boolean prevState;
long val = 2;
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
pinMode(25, OUTPUT);
pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
digitalWrite (output7,LOW);
digitalWrite (4,LOW);
//Serial.begin(9600);
// Mouse.begin();
digitalWrite (25,LOW);
}
const int channel = 16;
int controller7 = 7; // 7 = volume



void loop() {

digitalWrite (output7,LOW);
digitalWrite (4,LOW);


if (digitalRead(inbut18)==LOW){
  prevState=LOW;
  
}

if (digitalRead(18)==HIGH&&prevState==LOW){
 usbMIDI.sendNoteOn(60, 127, channel);  // 60 = C4
  prevState=HIGH;
 val=val*2;
  if (val>4)
    val=2;
 
}
  if (val==2){
    digitalWrite(red, HIGH);
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
    

  }
  else if (val==8){
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
  }
  else if (val==4){
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(green, HIGH);
  }

//Serial.print 

long Knob = myEnc.read();

if (Knob  < 1 ){
Knob = 0;
  myEnc.write(0);
}

if (Knob  >126 ){
Knob = 127;
myEnc.write(127);
} 

delay(10);

if (Knob == myEnc.read()){

}




 if (Knob < myEnc.read()){
 usbMIDI.sendControlChange(controller7, Knob, channel);
 Serial.println (Knob);
 }
else if (Knob > myEnc.read()){
 usbMIDI.sendControlChange(controller7, Knob, channel);
 Serial.println (Knob);
 }


    
delay (10);



}

