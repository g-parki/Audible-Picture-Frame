#include <SPI.h>
#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include <SD.h>

TMRpcm audio;
int reading = 0;

void setup(void)
{
  audio.speakerPin = 9;
  audio.setVolume(5);
  audio.quality(1);
  Serial.begin(9600);
  if (!SD.begin())
  {
    Serial.println("SD failed");
    while (true)
      ;
  }
  else
  {
    Serial.println("SD worked");
  }
}

void loop(void)
{
  if (!audio.isPlaying())
  {
    reading = analogRead(A1);
    Serial.println(reading);
  }
  else
  {
    reading = 0;
  }

  if (reading >= 100)
  {
    audio.play("vm.wav");
  }

  delay(100);
}