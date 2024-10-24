#include <Servo.h>

Servo myServoX; // Servo motor for X-axis 
Servo myServoY; // Servo motor for Y-axis 

const int ServoXPin = 10; // X-axis pin
const int ServoYPin = 9; // Y-axis pin
const int ServoXHomePos = 90; // Home position for X servo
const int ServoYHomePos = 90; // Home position for Y servo
const int ServoXMinPos = 0; // Min position for X servo
const int ServoXMaxPos = 180; // Max position for X servo
const int ServoYMinPos = 0; // Min position for Y servo
const int ServoYMaxPos = 180; // Max position for Y servo

const int XAxlePin = A0; // Joystick X-axis pin
const int YAxlePin = A1; // Joystick Y-axis pin

const int range = 12; // Output range of X or Y movement
const int center = range / 2; // Resting position value
const int threshold = range / 4; // Resting threshold

// Speed adjustment
const int speedFactor = 2; // Increase this value for faster movement

void setup() {
    myServoX.attach(ServoXPin); // Attaching servo X 
    myServoY.attach(ServoYPin); // Attaching servo Y
    myServoX.write(ServoXHomePos); // Set initial position
    myServoY.write(ServoYHomePos); // Set initial position
    Serial.begin(9600); // Start serial communication
}

void loop() {
    int XAxleValue = readAxis(XAxlePin);
    int YAxleValue = readAxis(YAxlePin);

    Serial.print("X: ");
    Serial.print(XAxleValue);
    Serial.print(" - Y: ");
    Serial.println(YAxleValue);

    // Move servos based on joystick input
    moveServos(XAxleValue, YAxleValue);

    delay(20); // Delay for stability and responsiveness
}

int readAxis(int thisAxis) {
    int reading = analogRead(thisAxis);
    reading = map(reading, 0, 1023, 0, range);
    int distance = reading - center;

    return (abs(distance) < threshold) ? 0 : distance; // Return distance or 0
}

void moveServos(int XValue, int YValue) {
    static int ServoXPos = ServoXHomePos;
    static int ServoYPos = ServoYHomePos;

    // Adjust X-axis servo position
    if (XValue != 0) {
        ServoXPos += (XValue > 0) ? -speedFactor : speedFactor; // Faster movement
    }

    // Adjust Y-axis servo position
    if (YValue != 0) {
        ServoYPos += (YValue > 0) ? speedFactor : -speedFactor; // Faster movement
    }

    // Constrain servo positions
    ServoXPos = constrain(ServoXPos, ServoXMinPos, ServoXMaxPos);
    ServoYPos = constrain(ServoYPos, ServoYMinPos, ServoYMaxPos);

    // Update servos only if positions changed
    myServoX.write(ServoXPos);
    myServoY.write(ServoYPos);
}
