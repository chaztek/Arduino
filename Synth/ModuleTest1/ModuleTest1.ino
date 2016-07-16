
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// GUItool: begin automatically generated code
//AudioSynthWaveformSine   sine3;          //xy=188,340
//AudioSynthWaveformSine   sine4;          //xy=188,379
AudioSynthWaveformSine   sine1;          //xy=189,259
//AudioSynthWaveformSine   sine2;          //xy=189,301
AudioMixer4              mixer1;         //xy=402,321
AudioOutputI2S           i2s1;           //xy=557,322
//AudioConnection          patchCord1(sine3, 0, mixer1, 2);
//AudioConnection          patchCord2(sine4, 0, mixer1, 3);
AudioConnection          patchCord3(sine1, 0, mixer1, 0);
//AudioConnection          patchCord4(sine2, 0, mixer1, 1);
AudioConnection          patchCord5(mixer1, 0, i2s1, 0);
AudioConnection          patchCord6(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=234,455
// GUItool: end automatically generated code


void setup() {
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
  sine1.frequency(440);
 // sine2.frequency(440);
//  sine3.frequency(440);
//  sine4.frequency(440);
  sine1.amplitude(1.0);
 // sine2.amplitude(1.0);
//  sine3.amplitude(1.0);
//  sine4.amplitude(1.0);
  mixer1.gain(0, 1.0);
 // mixer1.gain(1, 1.0);
//  mixer1.gain(2, 1.0);
//  mixer1.gain(3, 1.0);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  //Serial.begin(115200);
}

void loop() {
  sine1.frequency(440);
  //sine2.frequency(analogRead(15));
//  sine3.frequency(analogRead(16));
//  sine4.frequency(analogRead(17));
  //Serial.println(analogRead(14));
  delay(1000);
  Serial.begin(115200);
  Serial.println(analogRead(14));
  Serial.end();
}
