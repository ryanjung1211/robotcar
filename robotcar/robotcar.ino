#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
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

void stop(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void setup(){
}
void loop(){
  moveForward()
  move
}
