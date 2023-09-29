#include <Servo.h>

int servo1_pos = 90;
int servo2_pos = 90;
int servo3_pos = 90;

Servo ESC1;
Servo ESC2;
Servo ESC3;
void setup(void)
{
  ESC1.attach(3);
  ESC2.attach(5);
  ESC3.attach(6);

  ESC1.write(servo1_pos);
  ESC2.write(servo2_pos);
  ESC3.write(servo3_pos);
  
  Serial.begin(9600);
}

void loop(void)
{
  char val = Serial.read();
  switch (val)
  {
    case 'q':
    case 'Q':
      servo1_pos = servo1_pos + 20;
      if (servo1_pos > 180){
        servo1_pos = 180;
      }
      ESC1.write(servo1_pos);
      break;
    case 'a':
    case 'A':
      servo1_pos = servo1_pos - 20;
      if (servo1_pos < 0){
        servo1_pos = 0;
      }
      ESC1.write(servo1_pos);
      break;
    case 'w':
    case 'W':
      servo2_pos = servo2_pos + 20;
      if (servo2_pos > 180){
        servo2_pos = 180;
      }
      ESC2.write(servo2_pos);
      break;
    case 's':
    case 'S':
      servo2_pos = servo2_pos - 20;
      if (servo2_pos < 0){
        servo2_pos = 0;
      }
      ESC2.write(servo2_pos);
      break;
    case 'e':
    case 'E':
      servo3_pos = servo3_pos + 20;
      if (servo3_pos > 180){
        servo3_pos = 180;
      }
      ESC3.write(servo3_pos);
      break;
    case 'd':
    case 'D':
      servo3_pos = servo3_pos - 20;
      if (servo3_pos < 0){
        servo3_pos = 0;
      }
      ESC3.write(servo3_pos);
      break;
  }
}
