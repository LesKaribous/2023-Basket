#include <Arduino.h>
#include <Servo.h>
#include <Adafruit_NeoPixel.h>

#define PIN 9

const int pinServo  = 11;
const int pinLed    = 13;
const int pinSensor = 10;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(7, PIN, NEO_GRB + NEO_KHZ800);

const int timeout = 5000;
int elapsedTime = 0;

Servo elevator ;

void setColor(uint32_t c);

void setup() 
{
  pinMode(pinLed,OUTPUT);
  pinMode(pinSensor,INPUT);

  digitalWrite(pinLed,HIGH);

  strip.begin();
  strip.setBrightness(50);
  strip.show();

  setColor(strip.Color(0, 0, 255));
  elevator.attach(pinServo);
  elevator.write(120);
  delay(2000);
  elevator.writeMicroseconds(1000);
  elevator.detach();
  delay(2000);
  elapsedTime = millis();
  setColor(strip.Color(0, 255, 0));
}

void loop() 
{
  if(!digitalRead(pinSensor))
  {
    setColor(strip.Color(255, 0, 0));
    elevator.attach(pinServo);
    elevator.write(120);
    delay(5000);
    elevator.writeMicroseconds(1000);
    elevator.detach();
    setColor(strip.Color(0, 255, 0));
  }
  /*
  if(millis()-elapsedTime > timeout)
  {
    elevator.attach(pinServo);
    elevator.write(120);
    delay(80);
    elevator.writeMicroseconds(1000);
    elevator.detach();

    elapsedTime = millis();
  }
  */
}

void setColor(uint32_t c) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
    }
    strip.show();
  }
}