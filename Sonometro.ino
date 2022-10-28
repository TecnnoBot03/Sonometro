// C++ code
//

#include <Adafruit_NeoPixel.h>

#define PIN 6

#define NUMPIXELS 12

float datos = A0;

float pin1 = 0;

int calculo1 = 0;

int brillo = A5; 

int pin2 = 0;

float calculo2 = 0;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  pixels.begin();
}

void loop()
{
  pixels.clear();
  pin1 = analogRead(datos);
  pin2 = analogRead(brillo);
  Serial.println(pin1);
  calculo1 = map(pin1, 300, 700, 0, 11);
  calculo2 = map(pin2, 0, 1023, 0, 100);
  Serial.println(calculo1);
  for (int i=0; i<calculo1; i++) {
    pixels.setPixelColor(i, pixels.Color(0, (25 * calculo2), (25 * calculo2)));
  
  pixels.show();
  delay(20);
    
    }
  delay(250);
}
