//   *****This project is Developed by: Ensaf Atef ***** 
//              email:ensafatef@gmail.com

//The code is compatible with both ultrasonic HC-SRO 4 & SRF 04
//Connect SRF 04 to 1Sheeld like this: 
//Vcc >> +5 ..... Tri >> digital pin #12 .... Echo >> digital pin #13 .... GND >> Gnd

#include <VibrationShield.h>
#define CUSTOM_SETTINGS
#define INCLUDE_TEXT_TO_SPEECH_SHIELD
#define INCLUDE_VIBRATION_SHIELD


/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* This pattern waits for 1 second and vibrate for 2, 3 times. */
int pattern[6] = {1000,2000,1000,2000};
int patternSize = 6;

#include "Ultrasonic.h"
Ultrasonic ultrasonic(12,13);
int distance;


void setup()
{
  /* Start communication. */
  OneSheeld.begin();
}

void loop()
{
  distance=ultrasonic.Ranging(CM);
  if (distance < 50)
  { 
    /* Vibrate as the first pattern once. */
  Vibration.start(patternSize,pattern);
  
  /* Wait for 3 seconds. */
  OneSheeld.delay(3000);

  /* Stop the vibration. */
  Vibration.stop();

  TextToSpeech.say("Mom is coming");
  }
}
