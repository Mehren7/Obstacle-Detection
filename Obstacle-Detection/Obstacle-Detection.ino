int trigPin = 3;
int echoPin = 2;
int led = 8;

long duration, distance;

void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(100);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    distance = (duration * 0.034) / 2; // Convert time to distance
    
    Serial.print(distance);
    Serial.println(" cm");
    
    if (distance > 10) {
        digitalWrite(led, LOW);
    } else {
        digitalWrite(led, HIGH);
    }
    
    delay(1000);
}

