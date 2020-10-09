#include <Servo.h>

Servo myservo;  // myservo is an object of Servo class


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  myservo.write(90);  // sweep the servo by 90 degree
  delay(1000);        // wait for 1 second
  myservo.write(0);   // sweep the servo back to 0 degree
  delay(1000);        // wait for 1 second
}