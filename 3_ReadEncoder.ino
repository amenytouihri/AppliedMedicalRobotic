/*
   7MRI0060 - Applied Medical Robotics Module
   September 2024
   Author: Harry Robertshaw

   Purpose: Read encoder
*/

// Define the pins connected to encoder channels A and B
#define outputA 2
#define outputB 3

// Initialise variables to keep track of encoder state and position
int counter = 0; // Keeps track of the position (not used in this version)
int aState;      // Current state of channel A
int bState;      // Current state of channel B
int aLastState;  // Previous state of channel A
int bLastState;  // Previous state of channel B

void setup() { 
  // Set the encoder pins as inputs with internal pull-up resistors enabled
  pinMode(outputA, INPUT_PULLUP);
  pinMode(outputB, INPUT_PULLUP);

  // Start serial communication at 9600 baud to monitor the encoder state
  Serial.begin(9600);

  // Read the initial states of the encoder channels
  aLastState = digitalRead(outputA); // Store the initial state of channel A
  bLastState = digitalRead(outputB); // Store the initial state of channel B
} 

void loop() { 
  // Read the current state of encoder channels A and B
  aState = digitalRead(outputA);
  bState = digitalRead(outputB);

  // Print the current states of channel A and B to the Serial Monitor
  Serial.print("State a: ");
  Serial.print(aState);
  Serial.print("  "); // space between values
  Serial.print("State b: ");
  Serial.println(bState);

  // Add a small delay between readings to reduce output frequency
  delay(500);
}


