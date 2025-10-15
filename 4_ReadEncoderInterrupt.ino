/*
   7MRI0060 - Applied Medical Robotics Module
   September 2024
   Author: Harry Robertshaw

   Purpose: Read encoder with interrupt
*/

// Define the pins connected to encoder channels A and B
// These are the digital pins where the encoder will be connected
#define outputA 6   // Channel A of the encoder is connected to pin 6
#define outputB 7   // Channel B of the encoder is connected to pin 7

// Declare variables
int counter = 0;      // Variable to track the position of the encoder (number of steps)
int aLastState;       // Variable to store the last known state of channel A

void setup() {
  // Setup pin modes for the encoder pins
  // INPUT_PULLUP mode enables the internal pull-up resistor so that the pin defaults to HIGH
  pinMode(outputA, INPUT_PULLUP);
  pinMode(outputB, INPUT_PULLUP);

  // Start serial communication at 9600 baud
  // This allows us to send data back to the computer for monitoring/debugging
  Serial.begin(9600);

  // Read the initial state of channel A
  // This is important so that we have a reference for detecting changes in the encoder's state
  aLastState = digitalRead(outputA);

  // Attach an interrupt to pin 6 (outputA)
  // The interrupt is triggered whenever the state of channel A changes (HIGH to LOW or LOW to HIGH)
  // When the interrupt is triggered, the function 'updateEncoder' is called
  attachInterrupt(digitalPinToInterrupt(outputA), updateEncoder, CHANGE);
}

void loop() {
  // In the main loop, we simply print the current position of the encoder
  // 'counter' is updated in the interrupt function and reflects the encoder's movement
  Serial.print("Position: ");
  Serial.println(counter);

  // Delay the loop to print the position every 500 milliseconds (0.5 seconds)
  delay(500);
}

// Interrupt Service Routine (ISR) - This function is called whenever channel A changes state
void updateEncoder() {
  // Read the current states of both encoder channels (A and B)
  // We need both channels to determine the direction of rotation
  int aState = digitalRead(outputA);
  int bState = digitalRead(outputB);

  // Check if the state of channel A has changed since the last reading
  if (aState != aLastState) {
    // Determine the direction of rotation by comparing the states of A and B
    // If A and B are different, the encoder is rotating clockwise
    // If A and B are the same, the encoder is rotating counterclockwise
    if (aState == bState) {
      counter++;  // Clockwise rotation
    } else {
      counter--;  // Counterclockwise rotation
    }
  }
  // Update the last known state of channel A for the next comparison
  aLastState = aState;
}
