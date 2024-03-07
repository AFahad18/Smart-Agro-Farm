#include <Servo.h>

//Declare the servo pin
int servoPin = 7;
int p = 0;

//Create a servo object
Servo Servo1;

void setup() {
  // we need to attach the servo to the used pin number
  Servo1.attach(servoPin);
  Servo1.write(180);
}

void loop() {
  
  for(p = 0;p<=180;p++){
    Servo1.write(p);
    delay(10);
  }
  for(p = 180;p>=0;p--){
    Servo1.write(p);
    delay(10);
  }
//  digitalWrite(servoPin,HIGH);
//  // Make servo go to 0 degree
//  Servo1.write(0);
//  delay(1000);
//  //Make servo go to 90 degree
//  Servo1.write(90);
//  delay(1000);
//  //Make servo go to 180 degree
//  Servo1.write(180);
//  delay(1000);

}
