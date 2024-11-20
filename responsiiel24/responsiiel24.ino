#include <Servo.h>  // Include the Servo library
const int servoInput = 4;
const int servoPin = 9;
const int motorLow = 10;
const int motorHigh = 11;

Servo myServo;            // Create a servo object

void setup() {
  pinMode(servoInput, INPUT);
  pinMode(servoPin, OUTPUT);
  pinMode(motorLow, OUTPUT);
  pinMode(motorHigh, OUTPUT);
  digitalWrite(motorLow, HIGH);
  digitalWrite(motorHigh, HIGH);
  
  myServo.attach(servoPin);          // Attach the servo to the servo pin
  myServo.write(0);                  // Set servo to initial position (0 degrees)
}

void loop() {
  if(digitalRead(servoInput) == HIGH){
    myServo.write(90);
    delay(1000);
    myServo.write(0);
    delay(1000);
    }
  delay(10);  // Small delay to avoid rapid changes
}
