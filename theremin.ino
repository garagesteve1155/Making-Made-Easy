int sensor_level = 0;
int tone_on = 0;
int sensorValues[10]; // Array to store the last 10 sensor readings
int sensorIndex = 0;  // Index to keep track of the current position in the array
int numReadings = 15; // Number of readings to average

void setup() {
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the sensor value
  sensorValues[sensorIndex] = analogRead(A7);

  // Increment the index for the next reading
  sensorIndex = (sensorIndex + 1) % numReadings;

  // Calculate the average of the last 'numReadings' values
  int sum = 0;
  for (int i = 0; i < numReadings; i++) {
    sum += sensorValues[i];
  }
  sensor_level = sum / numReadings;

  Serial.println(sensor_level);

  if (sensor_level < 825) {
    noTone(5);
    tone_on = 0;
  } else {
    if (tone_on < 1) {
      tone(5, 250);
      tone_on = 1;
    }
  }
  delay(1);
}
