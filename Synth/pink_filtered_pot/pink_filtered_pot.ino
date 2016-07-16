#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// GUItool: begin automatically generated code
AudioSynthNoisePink      pink1;          //xy=157,429
AudioInputI2S            i2s2;           //xy=197,292
AudioFilterStateVariable filter2;        //xy=469,459
AudioFilterStateVariable filter1;        //xy=474,382
AudioOutputI2S           i2s1;           //xy=761,355
AudioConnection          patchCord1(i2s2, 0, filter1, 0);
AudioConnection          patchCord2(i2s2, 1, filter2, 0);
AudioConnection          patchCord3(filter2, 1, i2s1, 1);
AudioConnection          patchCord4(filter1, 1, i2s1, 0);
AudioControlSGTL5000     audioShield;     //xy=776,404
// GUItool: end automatically generated code


int potpin = 11;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 

void setup(void)
{
    // Set up
  AudioMemory(8);
  audioShield.enable();
  audioShield.volume(0.50);
 Serial.begin(38400);
    
}

void loop() {

  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
 val = map(val, 0, 1023, 0, 10000); 
 Serial.println(val);
  
  pink1.amplitude(1);
  filter1.frequency(val);
  filter1. resonance(5);                    //Q
   filter1.octaveControl(7);

}
