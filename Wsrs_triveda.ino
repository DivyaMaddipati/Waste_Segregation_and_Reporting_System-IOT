// Define the pins for the ultrasonic sensor
const int trigPin = 2; // Replace '2' with the pin you connected the Trig pin to.
const int echoPin = 3; // Replace '3' with the pin you connected the Echo pin to.

// Variables to store the duration and distance measured by the sensor
long duration;
int distanceCm;

void setup() {
  // Initialize the serial communication for debugging (optional)
  
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  
  // Set the trigPin as an output and echoPin as an input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigPin

  digitalWrite(13,LOW);
  digitalWrite(11,LOW);

    
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10 microseconds pulse to the trigPin to start the measurement
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration it takes for the ultrasonic pulse to return
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters (speed of sound in air is ~343 m/s)
  distanceCm = duration * 0.0343 / 2;

  if(distanceCm <= 2){
    digitalWrite(11,HIGH);
  }
  else{
    digitalWrite(13,HIGH);
  }
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  
  // Wait a short time before taking the next measurement
  delay(500);
}
