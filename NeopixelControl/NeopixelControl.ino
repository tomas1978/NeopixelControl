#include<Adafruit_NeoPixel.h>

#define PIN    2
#define N_LEDS  24

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

int readPotValue(int port) {
  int value=analogRead(port);
  return value;
}

void loop()
{
  int buttonEffect=0;
  if(digitalRead(buttonPin)==HIGH) {
    delay(10);
    Serial.println("Tryck");
    if(buttonEffect<3)
      buttonEffect++;
    else
      buttonEffect=0;
  }
  
  int potValue=readPotValue(0); //left end: 0, right end: 1023  
  Serial.println(potValue);
  int numberOfLeds=map(potValue,0,1023,0,24);
  
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
  for(int i=0;i<numberOfLeds;i++) {
  ring.setPixelColor(i, ring.Color(red,green,blue));
    ring.show();
    delay(10);
  }
}
