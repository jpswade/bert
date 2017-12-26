#define PWMA 5  //PWM puls width modula
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
/*
void fullSpeedA(void) {
  analogWrite(PWMA, PWMHIGH);
}*/

void CounterClockwiseA(void) {
  digitalWrite(DIRA, HIGH);
}

void ClockwiseA(void) {
  digitalWrite(DIRA, LOW);
}
void CounterClockwiseB(void) {
  digitalWrite(DIRB, LOW);
}

void ClockwiseB(void) {
  digitalWrite(DIRB, HIGH);
}


double W1 = 0.2; //W1 and W2 that will need to be added from the web interface in place of these integers
double W2 = 0.2;/*Note there seem to be peformance difrences between motors A and B 
perticularly at lower speeds I belleve this to be a hardware issue so likely to depends on the boards and mottors used*/

//AbsolutValue used to avoid errors when W1 or W2 are negative with the direction being handled sepratly
double AbsolutValueOfW1 = abs( W1 ) ;
double AbsolutValueOfW2 = abs( W2 );

//Variable used as a refrence point to relate the times on and off for each motor in micro seconds and varry the freqency they switch on and off
double MaxMotorTimeInterval = 50000;


double W1timeon = MaxMotorTimeInterval * AbsolutValueOfW1;
double W1timeoff = MaxMotorTimeInterval * (1 - AbsolutValueOfW1);
double W2timeon = MaxMotorTimeInterval * AbsolutValueOfW2;
double W2timeoff = MaxMotorTimeInterval * (1 - AbsolutValueOfW2);



void loop() {
  //mottor A on the left moveing Wheel 1 and B on the right moveing Wheel 2
  //if statments bellow are setting the mottors direction of rotation 
  if (W1 >= 0){
    ClockwiseA(); //Wheel1(W1)on the left clockwise. That is forwards when on bert
  
  }
  if (W1 < 0){
    CounterClockwiseA();//W1 counter clockwise backwards when on bert
  }
  if (W2 < 0){
    ClockwiseB();//W2 clockwise  backwards when on bert
  }
   if (W2 >= 0){
    CounterClockwiseB();//W2 counter clockwise forwards when on bert
  }
  


//B is switched on and off for W2 a propotional amount to W2timeon and W2timeoff while A is on and then while A is off
//so that one mottor dosn't have to wait for the other.
  digitalWrite(PWMA, HIGH);
  digitalWrite(PWMB, HIGH);
  delayMicroseconds(W2timeon * (W1timeon/MaxMotorTimeInterval));
  digitalWrite(PWMB, LOW);
  delayMicroseconds(W2timeoff * (W1timeon/MaxMotorTimeInterval));


  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, HIGH);
  delayMicroseconds(W2timeon * (W1timeoff/MaxMotorTimeInterval));
  digitalWrite(PWMB, LOW);
  delayMicroseconds(W2timeoff * (W1timeoff/MaxMotorTimeInterval));




}