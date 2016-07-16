#include <Encoder.h>

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder knob(6, 8);
//   avoid using pins with LEDs attached

long currentPosition;
const byte mouseMoveAmount = 1; // no idea what the units are for this, so tweak as needed
unsigned long lastMoveMillis;
int mouseReleaseTimer = 500; // time of no encoder move until mouse is released

void setup() {
 Mouse.begin();
 currentPosition = 0;
 knob.write(0);
}

void loop() {
 long newPosition = knob.read();

 if (newPosition != currentPosition) // has encoder position changed?
 {
   lastMoveMillis = millis(); // mark time of this move

  // if (!Mouse.isPressed())
    // Mouse.press(); // mouse left-button down

   Mouse.move(0, newPosition * mouseMoveAmount, 0); // move mouse up or down depending on direction of turn
 }

 if (millis() - lastMoveMillis > mouseReleaseTimer) // release the mouse and reset knob state to zero if sufficient time has elapsed.
 {
   Mouse.release();
   knob.write(0);
   newPosition = 0;
 } 

 currentPosition = newPosition;
}
