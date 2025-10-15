/*
   7MRI0060 - Applied Medical Robotics Module
   September 2024
   Author: Harry Robertshaw

   Purpose: Actuate motors via H-Bridge using PWM
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
  // Move Motor A CW at 75% speed for 2 seconds
  // tip: use digitalWrite() for direction, analogWrite() for speed
  analogWrite(mA_pinEnA, 190)
  digitalWrite(mA_pinIn1, HIGH)
  digitalWrite(mA_pinIn2, LOW)
  //we are not using the motor B so we comment it out so it is not working 
  //digitalWrite(mB_pinIn3, HIGH)
  //digitalWrite(mB_pinIn4, LOW)
  delay(2000) //sets the time for 2 minutes 

  // Move Motor A CCW at 50% speed
  // tip: use digitalWrite() for direction, analogWrite() for speed
  analogWrite(mA_pinEnA, 127)
  digitalWrite(mA_pinIn1, HIGH)
  digitalWrite(mA_pinIn2, LOW)
  //we are not using the motor B so we comment it out so it is not working 
  //digitalWrite(mB_pinIn3, HIGH)
  //digitalWrite(mB_pinIn4, LOW)
  delay(2000) //sets the time for 2 minutes 


  // Move Motor B CW at 75% speed for 2 seconds
  // tip: use digitalWrite() for direction, analogWrite() for speed
  //digitalWrite(mA_pinIn1, LOW)
  //digitalWrite(mA_pinIn2, HIGH)
  analogWrite(mB_pinEnB, 190)
  digitalWrite(mB_pinIn3, HIGH)
  digitalWrite(mB_pinIn4, LOW)
  delay(2000) //sets the time for 2 minutes 

  // Move Motor B CCW at 50% speed
  // tip: use digitalWrite() for direction, analogWrite() for speed
  //digitalWrite(mA_pinIn1, LOW)
  //digitalWrite(mA_pinIn2, HIGH)
  analogWrite(mB_pinEnB, 127)
  digitalWrite(mB_pinIn3, HIGH)
  digitalWrite(mB_pinIn4, LOW)
  delay(2000) //sets the time for 2 minutes 

  // Stop both motors for 1 second
  digitalWrite(mA_pinEnA, LOW)
  digtalWrite(mB_pinEnB, LOW)
  delay(1000) 
}
