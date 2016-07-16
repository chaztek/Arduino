//#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


touchRead   cs_4_2 = touchRead(4,3);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
//CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
//CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   pinMode(3,INPUT);
   Mouse.begin();
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.touchRead(200);
   // long total2 =  cs_4_6.capacitiveSensor(30);
   // long total3 =  cs_4_8.capacitiveSensor(30);
 
    Serial.println(millis() - start);        // check on performance in milliseconds
    Serial.println("\t");                    // tab character for debug windown spacing

    Serial.println(total1);                  // print sensor output 1
    //Serial.print("\t");
   // Serial.print(total2);                  // print sensor output 2
    //Serial.print("\t");
    //Serial.println(total3);                // print sensor output 3
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
    
    
    delay(50);                             // arbitrary delay to limit data to serial port 
}
