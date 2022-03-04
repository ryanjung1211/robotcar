#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define LT_RIGHT 10
#define LT_MIDDLE 4
#define LT_LEFT 2

#include<Servo.h>
Servo servo;

void setup(){
  pinMode(A5, OUTPUT);
  pinMode(A4, INPUT);
  Serial.begin(9600);
  servo.attach(3);
  pinMode(LT_RIGHT, INPUT);
  pinMode(LT_MIDDLE, INPUT);
  pinMode(LT_LEFT, INPUT);
  
}

double getDistance(){
  digitalWrite(A5, LOW);
  delayMicroseconds(2);
  digitalWrite(A5, HIGH);
  delayMicroseconds(10);
  digitalWrite(A5, LOW);
  
  long raw = pulseIn(A4, HIGH);
  double distance = raw * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  
  return distance;
}
void stop(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
void moveForward(){
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moveBackward(){
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft(){
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight(){
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void obstacle(){
  float d = getDistance();
  if (d < 15) {
    stop();
    servo.write(180);
    delay(400);
    float a = getDistance();
    if (a > 15) {
      turnLeft();
      delay(1000);
      servo.write(90);
      stop();
    }
    else{
      servo.write(0);
      delay(400);
      float c = getDistance();
      if (c > 15) {
        turnRight();
        delay(1000);
        stop();
        servo.write(90);
      }
      else {
        turnRight();
        delay(2000);
        stop();
        servo.write(90);
      }
      }
    }
}
void line_track(){
  int left = digitalRead(LT_LEFT);
  int middle = digitalRead(LT_MIDDLE);
  int right = digitalRead(LT_RIGHT);

  if (not left and not middle and not right){
    stop();
    delay(3000);
  }
  else if (left and not right){
    while (left and not right){
      turnLeft();
      int left = digitalRead(LT_LEFT);
      int right = digitalRead(LT_RIGHT);
    }
    
  }
  else if (right and not left){
    while (right and not left){
      turnRight();
      int right = digitalRead(LT_RIGHT);
      int left = digitalRead(LT_LEFT);
    }
  }
}

void loop(){
  moveForward();
  line_track();
}
