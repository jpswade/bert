#define PWMA 5
#define DIRA 0
#define PWMB 4
#define DIRB 2

#define led_pin D0

#define PWMA D1
#define PWMB D2

#define DIRA D3
#define DIRB D4

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

void fullSpeedA(void) {
  analogWrite(PWMA, PWMHIGH);
}

void forwardA(void) {
  digitalWrite(DIRA, HIGH);
}

void backwardA(void) {
  digitalWrite(DIRA, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Test Motor A Forward...");
  fullSpeedA();
  forwardA();
  delay(1000);

  Serial.println("Backwards Motor A...");
  backwardA();
  delay(1000);

  Serial.println("Backwards Motor B...");
  analogWrite(PWMB, PWMHIGH);
  digitalWrite(DIRB, LOW);
  delay(1000);

  Serial.println("Forward Motor B...");
  analogWrite(PWMB, PWMHIGH);
  digitalWrite(DIRB, HIGH);
  delay(1000);

  Serial.println("Loop...");
}
