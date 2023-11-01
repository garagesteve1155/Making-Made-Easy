const int trigPin = 2;
const int echoPin = 3;
const int ledpin = 4;
float duration;
float distance;
char ledData;
int ledState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledpin, OUTPUT);
  Serial1.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2; //distance in centimeters
  Serial1.println(distance);
  if (Serial1.available() > 0){
    ledData = Serial1.read();
    if (ledData == 'x'){
      if (ledState == 1){
        ledState = 0;
        digitalWrite(ledpin, LOW);
      }
      else if (ledState == 0){
        ledState = 1;
        digitalWrite(ledpin, HIGH);
      }
    }
    
  }
  delay(100);
}
