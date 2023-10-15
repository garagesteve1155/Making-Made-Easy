#include <Arduino.h>
const int speed1 = 11;
const int speed2 = 12;
const int in1 = 5;
const int in2 = 6;
const int in3 = 7;
const int in4 = 8;
void setup(void)
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
  Serial.begin(9600);
}

void loop(void)
{
    char val = Serial.read();
    switch (val)
    {
      case 'w': // Move Forward
      case 'W':
        forward();
        break;
      case 's': // Move Backwards
      case 'S':
        reverse();
        break;
      case 'a': // Turn Left
      case 'A':
        left();
        break;
      case 'd': // Turn Right
      case 'D':
        right();
        break;
      case 'x': // Stop
      case 'X':
        stopping();
        break;
    }
    
  
}

void stopping(void) // Stop
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(speed1, 0);
  analogWrite(speed2, 0);
}

void forward(void)
{
  analogWrite(speed1, 150);
  analogWrite(speed2, 150);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(50);

}

void reverse(void)
{
  analogWrite(speed1, 150);
  analogWrite(speed2, 150);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(50);

}

void left(void)
{
  analogWrite(speed1, 190);
  analogWrite(speed2, 190);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(50);

}

void right(void)
{
  analogWrite(speed1, 190);
  analogWrite(speed2, 190);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(50);

}
