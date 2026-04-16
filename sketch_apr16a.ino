#include <Servo.h>

Servo myservo;

char m = 0;
int pos = 0;

// Sensor pins
#define S1 A0
#define S2 A1
#define S3 A2

// Motor pins

#define IN1 5
#define IN2 6
#define IN3 9
#define IN4 10

// Pump
#define PUMP 7

// ---------- FUNCTIONS ----------

void stopMotors() {
  // analogWrite(ENA, 0);
  // analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void moveForward() {


digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);

digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
}

void moveBackward() {


  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {


  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {


  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void sprayWater() {
  stopMotors();

  digitalWrite(PUMP, LOW);   
  delay(2000);

  for (int i = 0; i < 2; i++) {
    for (pos = 0; pos <= 60; pos++) {
      myservo.write(pos);
      delay(15);
    }
    for (pos = 60; pos >= 0; pos--) {
      myservo.write(pos);
      delay(15);
    }
  }

  digitalWrite(PUMP, HIGH);  // OFF
}

// ---------- SETUP ----------

void setup() {
  Serial.begin(9600);

  myservo.attach(3);

  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);
  pinMode(S3, INPUT_PULLUP);


  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(PUMP, OUTPUT);
  digitalWrite(PUMP, HIGH);   // Ensure pump OFF at startup

  stopMotors();   
}

// ---------- LOOP ----------

void loop() {

  if (Serial.available()) {
    m = Serial.read();
  }

  // -------- AUTO MODE --------
if (m == 'S') {  

  int a = analogRead(S1);  
  int b = analogRead(S2);  
  int c = analogRead(S3);  

  Serial.print(a); Serial.print(" ");  
  Serial.print(b); Serial.print(" ");  
  Serial.println(c);  

  // 💧 VERY VERY CLOSE → spray  
  if (a < 90 || b < 90 || c < 90) {  
    sprayWater();  
  }  

  // 🔄 MID RANGE → move forward  
  else if ((a < 900 && a > 90) ||  
           (b < 900 && b > 90) ||  
           (c < 900 && c > 90)) {  
    moveForward();  
  }  

  // ❗ No fire  
  else {  
    stopMotors();  
  }  
}
  // -------- MANUAL MODE --------
  else if (m == 'F') moveForward();
  else if (m == 'B') moveBackward();
  else if (m == 'L') turnLeft();
  else if (m == 'R') turnRight();
  else if (m == 'V') sprayWater();

  // -------- SAFETY --------
  else {
    stopMotors();
  }
}