#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise1;         //xy=197,508
AudioOutputI2S           i2s1;           //xy=761,355
AudioConnection          patchCord1(noise1, 0, i2s1, 0);
AudioConnection          patchCord2(noise1, 0, i2s1, 1);
AudioControlSGTL5000     audioShield;     //xy=586,175
// GUItool: end automatically generated code


void setup(void)
{
    // Set up
  AudioMemory(8);
  audioShield.enable();
  audioShield.volume(0.25);

    
}

void loop() {
  noise1.amplitude(.5);

}

