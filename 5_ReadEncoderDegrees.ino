/*
   7MRI0060 - Applied Medical Robotics Module
   September 2024
   Author: Harry Robertshaw

   Purpose: Read encoder with interrupt and measure motor angle
*/

// Define the pins connected to encoder channels A and B
#define outputA 6
#define outputB 7

// Define constants for pulses per revolution (PPR) and gear ratio (GR)
const float PPR = 360.0;   // Pulses per revolution of the encoder
const float GR  = 30.0;    // Gear ratio

// Declare variables
volatile int counter = 0;          // Encoder position in pulses (shared with ISR)
int aLastState;                     // Previous state of channel A
float positionInDegrees_m2 = 0.0;  // Motor angle in degrees

void setup() {
  // Setup pin modes for encoder pins
  pinMode(outputA, INPUT_PULLUP);
  pinMode(outputB, INPUT_PULLUP);

  // Start serial communication at 9600 baud
  Serial.begin(9600);

  // Read initial state of channel A
  aLastState = digitalRead(outputA);

  // Attach an interrupt to detect changes on channel A
  attachInterrupt(digitalPinToInterrupt(outputA), updateEncoder, CHANGE);
}

void loop() {
  // Convert encoder count to angular position in degrees
  positionInDegrees_m2 = ((float)counter / (PPR * GR)) * 360.0;

  // Print the motor position in degrees
  Serial.print("Position in Degrees (Motor 2): ");
  Serial.println(positionInDegrees_m2);

  // Reset counter if angle exceeds ±360° for clarity
  if (positionInDegrees_m2 > 360.0 || positionInDegrees_m2 < -360.0) {
    noInterrupts();       // Temporarily disable interrupts to safely reset
    counter = 0;
    interrupts();         // Re-enable interrupts
    positionInDegrees_m2 = 0.0;
    Serial.println("Position reset to 0 degrees.");
  }

  delay(500);  // Slow down print frequency
}

// Interrupt Service Routine (ISR)
// Called whenever channel A changes state
void updateEncoder() {
  int aState = digitalRead(outputA);  // Read current state of channel A
  int bState = digitalRead(outputB);  // Read current state of channel B

  // If the state of channel A has changed
  if (aState != aLastState) {
    // Determine direction of rotation
    if (aState == bState) {
      counter++;   // Clockwise rotation
    } else {
      counter--;   // Counterclockwise rotation
    }
  }

  // Update last known state of channel A
  aLastState = aState;
}
