#include<Adafruit_NeoPixel.h>

#define PIN    2
#define N_LEDS  24

Adafruit_NeoPixel ring = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  ring.begin();
}

void loop()
{
  ring.fill(0,0,0);
  for(int i=0;i<24;i++) {
  ring.setPixelColor(i, ring.Color(0,118,189));
    ring.show();
    delay(42);
  }
}
