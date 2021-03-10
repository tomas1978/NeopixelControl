#include<Adafruit_NeoPixel.h>

#define PIN    	2
#define N_LEDS  24

Adafruit_NeoPixel ring = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

#include<Adafruit_NeoPixel.h>

#define PIN		2
#define	N_LEDS	24

Adafruit_NeoPixel ring = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int buttonPin=7;
int red=0, green=0, blue=0;

void setup()
{
  pinMode(buttonPin,OUTPUT);
  ring.begin();
  Serial.begin(9600);
}

void setColour(int r, int g, int b) {
  red=r;
  green=g;
  blue=b;
}

void loop()
{
  int buttonEffect=0;
  if(digitalRead(buttonPin)==HIGH) {
    Serial.println("Tryck");
  	if(buttonEffect<3)
      buttonEffect++;
    else
      buttonEffect=0;
  }
  delay(10);
  switch(buttonEffect) {
  	case 0:
    	setColour(255, 0, 0);
    	break;
    case 1:
    	setColour(0, 255, 0);
    	break;
    case 2:
    	setColour(0, 0, 255);
    	break;
    default:
    	setColour(255,255,255);
    
  }
  ring.fill(0,0,0);
  for(int i=0;i<24;i++) {
	ring.setPixelColor(i, ring.Color(red,green,blue));
    ring.show();
    delay(42);
  }
}
