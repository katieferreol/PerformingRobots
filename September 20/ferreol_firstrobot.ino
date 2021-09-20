#include <Servo.h>

// create servo object to control a servo
Servo armservo;
Servo headservo;

// variable to store the servo position
int pos = 0;
int pos2 = 0;

void setup() {
  armservo.attach(9);
  headservo.attach(7);
}

void loop() {

  //rotate and head and arm both at 90 degrees (one at a time)
  for (pos = 0; pos <= 90; pos += 1)
    // in steps of 1 degree
    armservo.write(pos);
  delay(15);
}
for (pos = 90; pos >= 0; pos -= 1) {
  armservo.write(pos);
  delay(15);
}
for (pos2 = 0; pos2 <= 90; pos2 += 1) {
  // in steps of 1 degree
  headservo.write(pos2);
  delay(15);
}
for (pos2 = 90; pos2 >= 0; pos2 -= 1) {
  headservo.write(pos2);
  delay(15);
}
}
