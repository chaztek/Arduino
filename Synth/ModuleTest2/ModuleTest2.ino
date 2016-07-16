#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=180,274
AudioMixer4              mixer1;         //xy=324,371
AudioOutputI2S           i2s1;           //xy=557,322
AudioConnection          patchCord1(i2s2, 0, mixer1, 0);
AudioConnection          patchCord2(i2s2, 1, mixer1, 1);
AudioConnection          patchCord3(mixer1, 0, i2s1, 0);
AudioConnection          patchCord4(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=234,455
// GUItool: end automatically generated code



void setup() {
  // put your setup code here, to run once:
  AudioMemory(12);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN);
  sgtl5000_1.audioPreProcessorEnable();
  sgtl5000_1.audioPostProcessorEnable();
  //pinMode(13, OUTPUT);
  //digitalWrite(13, HIGH);
  //Serial.begin(115200);
  //AudioProcessorUsageMaxReset();
  //AudioMemoryUsageMaxReset();
}

void loop() {
 mixer1.gain(1,1.0);
 mixer1.gain(2,1.0);
 //Serial.println("1");
 delay(500);

}
