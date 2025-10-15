/*
   7MRI0060 - Applied Medical Robotics Module
   September 2024
   Author: Harry Robertshaw

   Purpose: Actuate motors via H-Bridge
*/

// Define motor control pins
const int mA_pinIn1 = 5;       // Motor A - direction control pin In1
const int mA_pinIn2 = 6;       // Motor A - direction control pin In2
const int mA_pinEnA = 7;       // Motor A - enable pin EnA
const int mB_pinIn3 = 9;       // Motor B - direction control pin In3
const int mB_pinIn4 = 10;       // Motor B - direction control pin In4
const int mB_pinEnB = 11;       // Motor B - enable pin EnB

void setup() {
  // Set the motor control pins as output 
  // tip: use pinMode() function
  //Motor A
  pinMode(mA_pinIn1, OUTPUT)
  pinMode(mA_pinIn2, OUTPUT)

  //Motor B
  pinMode(mB_pinIn3, OUTPUT)
  pinMode(mb_pinI4, OUTPUT)

  pinMode(mA_pinEnA, OUTPUT)
  pinMode(mB_pinEnB, OUTPUT)  
}

void loop() {
  
  // Move Motor A CCW at full speed for 2 seconds
  // tip: use digitalWrite() function
  //Each motor has two pins we have to set one HIGH and one LOW when 1 is HIGH and 2 is LOW 
  //we know it is going in one direction and other wise it is the different direction 
  //setting both pins to HIGH will just block the turning and to LOW will just stop them
  digitalWrite(mA_pinIn1, HIGH) 
  digitalWrite(mA_pinIn2, LOW)

  //we are not using the motor B so we comment it out so it is not working 
  //digitalWrite(mB_pinIn3, HIGH)
  //digitalWrite(mB_pinIn4, LOW)
  delay(2000) //sets the time for 2 minutes 

  // Move Motor B CW at full speed for 2 seconds
  // tip: use digitalWrite() function
  //we are not using the motor A so we comment it out so it is not working 
  //digitalWrite(mA_pinIn1, LOW)
  //digitalWrite(mA_pinIn2, HIGH)

  digitalWrite(mB_pinIn3, HIGH)
  digitalWrite(mB_pinIn4, LOW)
  delay(2000) //sets the time for 2 minutes 

  // Stop both motors for 1 second
  //we just have to turn off the enable pins so they won't use the power
  digitalWrite(mA_pinEnA, LOW)
  digtalWrite(mB_pinEnB, LOW)
  delay(1000) 
  ...
}
