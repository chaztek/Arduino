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

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(8,6);
//   avoid using pins with LEDs attached
int inbut18 = 18;
boolean prevState;
long val = 2;
 int mode = 0;

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
//Keyboard.begin();
}


void loop() {
//Keyboard.begin();

digitalWrite (output7,LOW);
//digitalWrite (4,LOW);
if (digitalRead(inbut18)==LOW){
  prevState=LOW;
}

if (digitalRead(18)==HIGH&&prevState==LOW){
  prevState=HIGH;
  Keyboard.set_media(KEY_MEDIA_MUTE);
    Keyboard.send_now();
    Keyboard.set_media(0);
    Keyboard.send_now(); 
  Serial.println("press");
  val=val+1;
  if (val>3)
    val=1;
}
  if (val==1){
    digitalWrite(red, HIGH);
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
  }
  else if (val==2){
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
  }
  else if (val==3){
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(green, HIGH);
    
  }








 
 long Knob = myEnc.read();

  
  if (Knob > 0){
Keyboard.set_media(KEY_MEDIA_VOLUME_INC);
    Keyboard.send_now();
    Keyboard.set_media(0);
    Keyboard.send_now(); 
  //Keyboard.write(0xAE);
 // Serial.println(0xAE);
  
 
  }

  else  if (Knob < 0){
Keyboard.set_media(KEY_MEDIA_VOLUME_DEC);
    Keyboard.send_now();
    Keyboard.set_media(0);
    Keyboard.send_now();
     // Keyboard.write(0xAF);
 //Serial.println(0xAF);
  } 
  myEnc.write(0);
delay(15);
  
  
  } 
