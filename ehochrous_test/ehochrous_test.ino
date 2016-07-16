#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=64,190
AudioMixer4              mixer1;         //xy=265,250
AudioEffectDelay         delay1;         //xy=394,317
AudioEffectChorus        chorus1;        //xy=530,155
AudioOutputI2S           i2s1;           //xy=700,261
AudioConnection          patchCord1(i2s2, 0, mixer1, 0);
AudioConnection          patchCord2(i2s2, 1, mixer1, 1);
AudioConnection          patchCord3(mixer1, delay1);
AudioConnection          patchCord4(delay1, 0, chorus1, 0);
AudioConnection          patchCord5(delay1, 0, i2s1, 0);
AudioConnection          patchCord6(delay1, 0, i2s1, 1);
AudioConnection          patchCord7(chorus1, 0, mixer1, 2);
AudioControlSGTL5000     sgtl5000_1;     //xy=729,344
// GUItool: end automatically generated code

// Number of samples in each delay line
#define CHORUS_DELAY_LENGTH (16*AUDIO_BLOCK_SAMPLES)
// Allocate the delay lines for left and right channels
short delayline[CHORUS_DELAY_LENGTH];

int n_chorus = 2;


const int myInput = AUDIO_INPUT_LINEIN;

void setup() {
  // allocate enough memory for the delay
  AudioMemory(150);
  
  // enable the audio shield
  sgtl5000_1.enable();
  sgtl5000_1.volume(1);
  sgtl5000_1.inputSelect(myInput);
sgtl5000_1.lineInLevel(5);
sgtl5000_1.audioPostProcessorEnable();
sgtl5000_1.lineOutLevel(3);
chorus1.begin(delayline,CHORUS_DELAY_LENGTH,n_chorus);
 
 delay1.delay(7, 230);

 mixer1.gain(0, 1);
  mixer1.gain(1, 1);
mixer1.gain(2, .4);
//mixer2.gain(0, 1);
//mixer2.gain(1, 1);

}

  void loop () {
  }

