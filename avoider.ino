#include <Servo.h>

const int trigPin = 4;
const int echoPin = 2;
float duration, distance;
float left_duration, left_distance;
float right_duration, right_distance;
int in1 = 11;
int in2 = 12;
int in3 = 7;
int in4 = 8;
Servo ESC1;

void setup() {
  ESC1.attach(3);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  // Turn off motors - Initial state
  ESC1.write(90);
  Serial.begin(9600);
  Serial.println("Starting");
}

void loop() {


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  if (distance < 50.0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    
    ESC1.write(160);
    delay(250);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    left_duration = pulseIn(echoPin, HIGH);
    left_distance = (left_duration * 0.0343) / 2;
    Serial.print("Left Distance: ");
    Serial.println(left_distance);
    delay(100);
    ESC1.write(20);
    delay(250);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    right_duration = pulseIn(echoPin, HIGH);
    right_distance = (right_duration * 0.0343) / 2;
    Serial.print("Right Distance: ");
    Serial.println(right_distance);
    delay(100);
    ESC1.write(90);
    if (left_distance > right_distance) {
      analogWrite(5, 120);
      analogWrite(6, 150);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      delay(450);
    } else if (left_distance < right_distance) {
      analogWrite(5, 150);
      analogWrite(6, 120);

      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(450);
    }
  } else {
      analogWrite(5, 120);
      analogWrite(6, 120);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    
      // Add a delay to control the loop frequency
      delay(100);
    
  }
  
}
