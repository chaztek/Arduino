/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(6, 8);
//   avoid using pins with LEDs attached
int output7 = 7;
void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
   pinMode(7, OUTPUT);
   digitalWrite (output7,LOW);
pinMode(20, INPUT);
pinMode(16, OUTPUT);
pinMode(17, OUTPUT);
pinMode(19, OUTPUT);
digitalWrite (16,HIGH);
digitalWrite (17,LOW);
digitalWrite (19,LOW);
}

long oldPosition  = -999;

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }
}
