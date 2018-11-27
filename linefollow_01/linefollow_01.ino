#include "Adafruit_TCS34725.h"

const int m1_enablePin = 9;
const int m1_1pin = 2;
const int m1_2pin = 3;

const int m2_enablePin = 10;
const int m2_1pin = 4;
const int m2_2pin = 5;
const int motorPower = 100;

Adafruit_TCS34725 tcs = Adafruit_TCS34725();

void setup() {
  pinMode(m1_enablePin , OUTPUT);
  pinMode(m1_1pin , OUTPUT);
  pinMode(m1_2pin , OUTPUT);
  pinMode(m2_enablePin , OUTPUT);
  pinMode(m2_1pin , OUTPUT);
  pinMode(m2_2pin , OUTPUT);
  
  analogWrite(m1_enablePin, motorPower);
  analogWrite(m2_enablePin, motorPower);
  
  Serial.begin(9600);
  if (tcs.begin()) {
    Serial.println("Found TCS3475");
  } else {
    Serial.println("No TCS34725 found");
    while (1);
  }
  delay(3000);
}

void loop() {
  uint16_t r, g, b, c, colorTemp, lux; //lux is intensity
  
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);
  
  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");

  if(c < 20){
    swingTurnRight(20);
  } else {
    swingTurnLeft(20);
  }
  
}
void swingTurnLeft(int period){
  digitalWrite(m1_1pin, LOW);
  digitalWrite(m1_2pin, LOW);
  digitalWrite(m2_1pin, LOW);
  digitalWrite(m2_2pin, HIGH);
  delay(period);
}

void swingTurnRight(int period){
  digitalWrite(m1_1pin, LOW); 
  digitalWrite(m1_2pin, HIGH);
  digitalWrite(m2_1pin, LOW);
  digitalWrite(m2_2pin, LOW);
  delay(period);
}
