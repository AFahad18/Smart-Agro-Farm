#include <SimpleDHT.h>
#include <Servo.h>

//Declare the servo pin
int servoPin = 7;
int p = 0;
int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 13l;


// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 4;

Servo Servo1;
SimpleDHT11 dht11(pinDHT11);

void setup() {
    // start working...
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(buzzPin, OUTPUT);
  Servo1.attach(servoPin);
  Servo1.write(180);
  
  Serial.begin(9600);
  Serial.println("Temp Data: ");
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration/2) / 29.1;
  if (distance < 3) {
  digitalWrite(buzzPin, HIGH);
  } else {

    digitalWrite(buzzPin, LOW);
  }
  //delay(60);
  Serial.print("S: ");
  Serial.print(distance);
  Serial.println(" cm.");

  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
  
 
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  if((int)temperature<20 || sensorValue<400){
    servoA();
  }
  else{
    servoB();
  }
}


void servoA(){
  Servo1.write(90);
}
void servoB(){
    Servo1.write(180);
}
