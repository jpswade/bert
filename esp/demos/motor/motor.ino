#define LED D0
#define PWMA 5 // 1,2EN aka D1 pwm left
#define DIRA 0 // 1A,2A aka D3
#define PWMB 4 // 3,4EN aka D2 pwm right
#define DIRB 2 // 3A,4A aka D4
#define PWMHIGH 1023
void setup() {
  Serial.begin(115200);
  Serial.println();
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA, OUTPUT);
  analogWrite(PWMA, LOW);
  digitalWrite(DIRA, LOW);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRB, OUTPUT);
  analogWrite(PWMB, LOW);
  digitalWrite(DIRB, LOW);
}
void loop() {
  Serial.println("Test Motor A...");
  analogWrite(PWMA, PWMHIGH);
  digitalWrite(DIRA, LOW);
  Serial.println("Test Motor B...");
  analogWrite(PWMB, PWMHIGH);
  digitalWrite(DIRB, LOW);
  delay(1000);
}
