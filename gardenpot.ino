int sensor_level;


int average = 0;
const int numReadings = 50; // Number of readings to average
int readings[numReadings];   // Array to store readings
int index = 0;              // Current index in the readings array
long total = 0; 


int led1 = 0;
int led2 = 0;
int led3 = 0;
int led4 = 0;

void setup(){  
  Serial.begin(9600);
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0; // Initialize the array
  }
  digitalWrite(2, HIGH);
}

void loop() {
  
  sensor_level = analogRead(A7);


  // Subtract the oldest reading from the total
  total -= readings[index];
  // Add the new reading to the total
  total += sensor_level;
  // Store the new reading in the array
  readings[index] = sensor_level;
  // Move to the next index in the array
  index = (index + 1) % numReadings;
  // Calculate the average
  average = total / numReadings;
  // if door stays open for 30 seconds, send text and start counter over
  Serial.println(average);

  
  if (average < 200 and led1 == 0){
    led1 = 1;
    digitalWrite(3,HIGH);
  }
  else if (average >= 200 and led1 == 1){
  led1 = 0;
  digitalWrite(3,LOW);
  }

  if (average < 130 and led2 == 0){
    led2 = 1;
    digitalWrite(4,HIGH);
  }
  else if (average >= 130 and led2 == 1){
  led2 = 0;
  digitalWrite(4,LOW);
  }

  if (average < 60 and led3 == 0){
    led3 = 1;
    digitalWrite(5,HIGH);
  }
  else if (average >= 60 and led3 == 1){
  led3 = 0;
  digitalWrite(5,LOW);
  }

  if (average <= 10 and led4 == 0){
    led4 = 1;
    digitalWrite(6,HIGH);
  }
  else if (average > 10 and led4 == 1){
  led4 = 0;
  digitalWrite(6,LOW);
  }


}
