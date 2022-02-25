#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

#include<Servo.h>
Servo servo;

void setup(){
  pinMode(A5, OUTPUT);
  pinMode(A4, INPUT);
  Serial.begin(9600);
  servo.attach(3);
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
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight(){
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void obstacle(){
  float d = getDistance();
  if (d < 15) {
    stop();
    servo.write(180);
    float a = getDistance();
    if (a > 15) {
      turnLeft();
      delay(1000);
      stop();
      servo.write(90);
    }
    else{
      delay(1000);
      servo.write(0);
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


void loop(){
  obstacle();
  delay(1000);
}
