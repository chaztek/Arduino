#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

AudioSynthWaveformSine sine1;          
AudioOutputAnalog dac1;           
AudioConnection patchCord2(sine1, 0, dac1, 0);

//long freq = 18500;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  AudioMemory(20);
  sine1.frequency(1300);
  sine1.amplitude(1.0);
}


void loop(){


  
}
