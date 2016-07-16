#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=275,239
AudioOutputAnalog        dac1;           //xy=465,313
AudioConnection          patchCord2(sine1,0, dac1,0);
// GUItool: end automatically generated code

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  AudioMemory(20);
  sine1.amplitude(1);
  sine1.frequency(1360);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
