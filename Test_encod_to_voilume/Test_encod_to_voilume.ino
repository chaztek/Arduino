

#include <Bounce.h>
#include <Encoder.h>

Bounce button18 = Bounce(18, 10);
Encoder myEnc(6,8);
int output7 = 7;

void setup() {
  // put your setup code here, to run once:
pinMode(18, INPUT);
pinMode(7, OUTPUT);

 digitalWrite (output7,LOW);

Encoder myEnc(6,8);
int output7 = 7;
}

void loop() {

 


  button18.update();
  
  if (button18.fallingEdge()) {
  Serial.println(1);
   // Keyboard.set_media(KEY_MEDIA_VOLUME_INC);
  //  Keyboard.send_now();
  //  Keyboard.set_media(0);
   // Keyboard.send_now();
  }
else if (button18.risingEdge()){
Serial.println(0);

  }
}
