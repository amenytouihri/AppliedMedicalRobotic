/*
   7MRI0060 - Applied Medical Robotics Module
   September 2024
   Author: Harry Robertshaw

   Purpose: Count LED blinks
*/

const byte ledPIN = 13;
volatile byte state = LOW;
unsigned int blinkCount = 0;

void setup() {
  // Initialize serial communication at a baud rate of 9600 bits per second.
  // This allows us to send messages from the Arduino to the computer.
  Serial.begin(9600);
  
  // Set the built-in LED pin (usually pin 13) as an output.
  // This prepares the LED for turning on and off.
  pinMode(ledPIN, OUTPUT);
}

void loop() {
  // Turn the built-in LED on (HIGH is the voltage level that powers the LED).
  digitalWrite(ledPIN, state);
  
  // Pause the program for 1000 milliseconds (1 second).
  // The LED will stay on during this time.
  delay(1000);

  // Toggle the LED state (on/off)
  state = !state;

  // Increment the blink counter
  blinkCount++;

  // Print the blink count to the Serial Monitor
  Serial.println(blinkCount);
}
