#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=242,299
AudioOutputAnalog        dac1;           //xy=465,313
AudioConnection          patchCord1(waveform1, dac1);
// GUItool: end automatically generated code


void setup() {
  AudioMemory(20);
  waveform1.begin(0.5, 100, WAVEFORM_SQUARE);
  //waveform1.pulseWidth(0.5);
}

void loop() {
  waveform1.frequency(1360);
  

}
