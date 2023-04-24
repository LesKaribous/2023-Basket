#include <Arduino.h>
#include <Servo.h>

const int pinServo  = 11;
const int pinLed    = 13;
const int pinSensor = 10;


const int timeout = 5000;
int elapsedTime = 0;

Servo elevator ;

void setup() 
{
  pinMode(pinLed,OUTPUT);
  pinMode(pinSensor,INPUT);

  digitalWrite(pinLed,HIGH);

  elevator.attach(pinServo);
  elevator.write(120);
  delay(2000);
  elevator.writeMicroseconds(1000);
  elevator.detach();
  delay(2000);
  elapsedTime = millis();
}

void loop() 
{
  if(!digitalRead(pinSensor))
  {
    elevator.attach(pinServo);
    elevator.write(120);
    delay(5000);
    elevator.writeMicroseconds(1000);
    elevator.detach();
  }
  if(millis()-elapsedTime > timeout)
  {
    elevator.attach(pinServo);
    elevator.write(120);
    delay(80);
    elevator.writeMicroseconds(1000);
    elevator.detach();

    elapsedTime = millis();
  }
}