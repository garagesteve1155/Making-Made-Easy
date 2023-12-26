int sensor;
int last_sensor;
unsigned long startTime = 0;
unsigned long interval = 5000; // 60 seconds in milliseconds

void setup() {
  Serial.begin(9600);
  pinMode(6, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

void loop() {
  sensor = digitalRead(6);
  Serial.println(sensor);
  if (sensor == 1 && last_sensor == 0) {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(2, HIGH);
    startTime = millis(); // Reset the timer when sensor is detected
  } 
  if (sensor == 1) {
    startTime = millis(); // Reset the timer when sensor is detected
  } 
  if (millis() - startTime >= interval) {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(2, LOW);
  }

  last_sensor = sensor;
  delay(10);
}
