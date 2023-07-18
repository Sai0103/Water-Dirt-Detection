// Pin assignments
const int turbidityPin = A0;    // Analog pin for turbidity sensor
const int redLEDPin = 2;        // Digital pin for red LED
const int greenLEDPin = 3;      // Digital pin for green LED
const int buzzerPin = 4;        // Digital pin for buzzer

// Threshold values
const int dirtThreshold = 0;  // Adjust this threshold based on your mapped turbidity values

void setup() {
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(turbidityPin);  // Read turbidity sensor value
  int turbidity = map(sensorValue, 0, 750, 100, 0);  

  Serial.print("Turbidity: ");
  Serial.println(turbidity);

  // Water is dirty
  if (turbidity > dirtThreshold) {
    digitalWrite(greenLEDPin, LOW); 
    
    // Blink the red LED and beep the buzzer 
    for (int i = 0; i < 4; i++) {    // Blink 4 times
      digitalWrite(redLEDPin, HIGH); // Turn on red LED
      digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
      delay(1000);                   // Wait for 1 second
      digitalWrite(redLEDPin, LOW);  // Turn off red LED
      digitalWrite(buzzerPin, LOW);  // Turn off the buzzer
      delay(1000);                   // Wait for 1 second
    }
  }
  // Water is clean
  else {
    digitalWrite(redLEDPin, LOW);    // Turn off red LED
    
    // Blink the green LED 
    for (int i = 0; i < 4; i++) {     // Blink 4 times
      digitalWrite(greenLEDPin, HIGH);// Turn on green LED
      delay(1000);                    // Wait for 1 second
      digitalWrite(greenLEDPin, LOW); // Turn off green LED
      delay(1000);                    // Wait for 1 second
    }
  }

  delay(1000);  // Wait for 2 seconds before checking again
}
