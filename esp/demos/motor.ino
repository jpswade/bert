#include <Wire.h>

// Assign Arduino Friendly Names to GPIO pins
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13

#define PWMA 5
#define DIRA 0
#define PWMB 4
#define DIRB 2

#define PWMHIGH 1024

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println("Starting...");
  Serial.println("Preparing motor A...");
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA, OUTPUT);
  analogWrite(PWMA, LOW);
  digitalWrite(DIRA, LOW);

  Serial.println("Preparing motor B...");
  pinMode(DIRB, OUTPUT);
  pinMode(PWMB, OUTPUT);
  analogWrite(PWMB, LOW);
  digitalWrite(DIRB, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Motor test");
  analogWrite(PWMA,LOW);
  digitalWrite(DIRA,HIGH);
  delay(1000);

  Serial.println("Starting motor...");
  Serial.println("Speed: 500");
  analogWrite(PWMA, PWMHIGH);
  delay(1000);

  Serial.println("End.");
}
