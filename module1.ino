#include "TFT_eSPI.h"
#include "smallpumpkin.h"
#include "scary_jackolantern.h"
#include "bat.h"

TFT_eSPI tft= TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

int smallpumpkinW=94;
int smallpumpkinH=86;

int scary_jackolanternW=94;
int scary_jackolanternH=86;

int batW=16;
int batH=11;

int screenW=240;
int screenH=135;

int start=1;
unsigned short imageS[32400]={0};

int counter = 0;

void setup() {
  // put your setup code here, to run once:
tft.init();
tft.setRotation(1);
tft.setSwapBytes(true);
tft.fillScreen(TFT_BLACK);

}


void loop() {
  // put your main code here, to run repeatedly:

tft.pushImage(65,20,smallpumpkinW,smallpumpkinH, smallpumpkin);
tft.pushImage(65,20,scary_jackolanternW,scary_jackolanternH,scary_jackolantern);

if(counter % 350) {
  tft.pushImage(random(tft.width() - batW), random(tft.height() - batH),  batW,  batH, bat);
}

counter++;

if(counter==10000){
  counter = 0;
    tft.setRotation(2 * random(2)); // Rotate randomly to clear display left>right or right>left to reduce monotony!
    tft.fillScreen(TFT_BLACK);
    tft.setRotation(1);
}
}
