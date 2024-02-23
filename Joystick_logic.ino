// Code for servo motors with joysticks
#include <Servo.h>


// Servo setup and create servo objects
Servo Servo1; // Create servo object to control a servo
Servo Servo2;
Servo Servo3;
Servo Servo4;


// Define servo pin variables for 4 different motors
const int servoPin_motor1 = 3; // Servo 1 connected to digital pin 3
const int servoPin_motor2 = 5; // Servo 2 connected to digital pin 5
const int servoPin_motor3 = 6; // Servo 3 connected to digital pin 6
const int servoPin_motor4 = 9; // Servo 4 connected to digital pin 9


// 4 Joystick's X-axis connected to analog pins
const int joystickXPin1 = A0; // Joystick 1 X-axis connected to analog pin A0
const int joystickXPin2 = A1; // Joystick 2 X-axis connected to analog pin A1
const int joystickXPin3 = A2; // Joystick 3 X-axis connected to analog pin A2
const int joystickXPin4 = A3; // Joystick 4 X-axis connected to analog pin A3


void setup() {
  // Begin serial communication
  Serial.begin(9600);


  // Attaching servos to digital pins
  //Servo_motor 1
  Servo1.attach(servoPin_motor1); // Attaches the servo_motor 1
  Servo1.write(90); // Set servo_motor 1 to home position (90 degrees)
  //Servo_motor 1
  Servo2.attach(servoPin_motor2); // Attaches the servo_motor 2
  Servo2.write(90); // Set servo_motor 1 to home position (90 degrees)
  //Servo_motor 1
  Servo3.attach(servoPin_motor3); // Attaches the servo_motor 1
  Servo3.write(90); // Set servo_motor 1 to home position (90 degrees)
  //Servo_motor 1
  Servo4.attach(servoPin_motor4); // Attaches the servo_motor 1
  Servo4.write(90); // Set servo_motor 1 to home position (90 degrees)
 


  // Joystick setup
  pinMode(joystickXPin1, INPUT); // Set joystick_1 X-axis as input
  pinMode(joystickXPin2, INPUT); // Set joystick_2 X-axis as input
  pinMode(joystickXPin3, INPUT); // Set joystick_3 X-axis as input
  pinMode(joystickXPin4, INPUT); // Set joystick_4 X-axis as input
}


void loop() {


  // Servo control with joystick
  // Servo_motor_1
  int joystickXValue1 = analogRead(joystickXPin1);
  int servoAngle1 = map(joystickXValue1, 0, 1023, 55, 125); // Map to +/- 40 degrees from center
  Servo1.write(servoAngle1);
  delay(15); // Delay for stability


    // Servo_motor_2
  int joystickXValue2 = analogRead(joystickXPin2);
  int servoAngle2 = map(joystickXValue2, 0, 1023, 55, 125); // Map to +/- 40 degrees from center
  Servo2.write(servoAngle2);
  delay(15); // Delay for stability


    // Servo_motor_3
  int joystickXValue3 = analogRead(joystickXPin3);
  int servoAngle3 = map(joystickXValue3, 0, 1023, 55, 125); // Map to +/- 40 degrees from center
  Servo3.write(servoAngle3);
  delay(15); // Delay for stability


    // Servo_motor_4
  int joystickXValue4 = analogRead(joystickXPin4);
  int servoAngle4 = map(joystickXValue4, 0, 1023, 55, 125); // Map to +/- 40 degrees from center
  Servo4.write(servoAngle4);
  delay(15); // Delay for stability
}
