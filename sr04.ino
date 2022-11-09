#define echoPin 2
#define trigPin 3

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite (8, LOW);
  digitalWrite (7, LOW);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  if (distance < 10) {
    digitalWrite (8, HIGH);
    digitalWrite(7, HIGH);
  }
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
