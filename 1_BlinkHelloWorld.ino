/*
   7MRI0060 - Applied Medical Robotics Module
   September 2024
   Author: Harry Robertshaw

   Purpose: Print Hello World and control an LED
*/

void setup() {
  // Initialize serial communication at a baud rate of 9600 bits per second.
  // This allows us to send messages from the Arduino to the computer.
  Serial.begin(9600);
  
  // Set the built-in LED pin (usually pin 13) as an output.
  // This prepares the LED for turning on and off.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Turn the built-in LED on (HIGH is the voltage level that powers the LED).
  digitalWrite(LED_BUILTIN, HIGH);
  
  // Pause the program for 1000 milliseconds (1 second).
  // The LED will stay on during this time.
  delay(1000);

  // Turn the built-in LED off (LOW cuts off the power).
  digitalWrite(LED_BUILTIN, LOW);
  
  // Pause the program for another 1000 milliseconds (1 second).
  // The LED will stay off during this time.
  delay(1000);

  // Print the message "Hello, world!" to the Serial Monitor.
  // This will display in the Arduino IDE's Serial Monitor.
  
  Serial.println("Hello, world!");

}
