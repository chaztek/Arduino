#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=188,259
AudioOutputI2S           i2s1;           //xy=557,322
AudioConnection          patchCord1(sine1, 0, i2s1, 0);
AudioConnection          patchCord2(sine1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=234,455
// GUItool: end automatically generated code



void setup() {
  // put your setup code here, to run once:
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
  sgtl5000_1.audioPostProcessorEnable();
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  AudioMemory(128);
  sine1.amplitude(1.0);
  sine1.frequency(1400);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sine1.frequency(analogRead(14));
}
