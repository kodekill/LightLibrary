#include <Adafruit_NeoPixel.h>
#include <IRremote.h>
#include "buttons.h"

#define LED_PIN 6  //2 on Cube  //3 on proto
#define RECV_PIN 4 //10 on Cube //6 on proto
#define NUM_PIX 4

IRrecv irrecv(RECV_PIN);
decode_results results;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIX, LED_PIN, NEO_GRB + NEO_KHZ800);

int default_intensity = 15;
int input = 0; //records remote input
int rate = 1;

float input_rate = 250; //usually is 250 for remote
String interval;

enum AnimationMode {
  FULL_ON,       //On Button
  BREATHE,       //
  BLINK,         //Flash Button
  CYCLE,         //Strobe Button
  CYCLE_BREATHE, //Fade Button
  MIX,            //Smooth Button
  SIRENS
} mode = FULL_ON;

typedef struct {
  int R;
  int G;
  int B;
  int intensity;
} RGB;

RGB color, colorPrime;

int Clamp(int x) { //Clamp sets my color input to a value between
  if (x <= 0)      // 0 and 255, it won't allow it to go over or under.
    return 0;

  else if (x > 255)
    return 255;

  else
    return x;
}

int Check_Input(int y) { //Check makes sure that my remote input can't 
  if (y <= 0)      // go over or under a certain range. 
    return 1;      // I need both Clamp and Check because with only 'Clamp'
                   // certain values will screw up the end LED output. 
  else if (y >= 255)
    return 255;

  else
    return y;
}

void increaseIntensity() {
  color.intensity = Check_Input(color.intensity + 20);
}

void decreaseIntensity() {
  color.intensity = Check_Input(color.intensity - 20);
}
