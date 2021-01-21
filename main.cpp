#include <Arduino.h>

int BLUE_PIN = 9;
int GREEN_PIN = 10;
int RED_PIN = 11;
int sensePin = A0;
int sensorInput;
double temp;



void setup() {
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorInput = analogRead(A0);
  temp = (double)sensorInput / 1024;
  temp = temp * 5;
  temp = temp - 0.5;
  temp = temp * 100;

  Serial.print("current temperature ");
  Serial.println(temp);
  
   if (temp > 10) {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
  }
  if (temp > 15) {
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  }
  if (temp < 10) {
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  
  
  delay(3000);

}
