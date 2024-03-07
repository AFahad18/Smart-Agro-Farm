int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 2;
void setup()
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); 
pinMode(buzzPin, OUTPUT);
Serial.begin(9600);
}
void loop()
{

int duration, distance;
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
// Distance is half the duration devided by 29.1 (from datasheet)
distance = (duration/2) / 29.1;
if (distance < 30) {
digitalWrite(buzzPin, HIGH);
} else {

digitalWrite(buzzPin, LOW);
}
delay(60);
  Serial.print("S: ");
  Serial.print(distance);
  Serial.println(" cm.");
}













//int echopin1 = 2;
//int trigpin1 = 6;
//int buzzer = 11;
//int time1;
//int cm1;
//
//
//
//
//void setup() {
//  // put your setup code here, to run once:
//  pinMode(trigpin1,OUTPUT);
//  pinMode(echopin1,INPUT);
//  Serial.begin(9600);
//
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  digitalWrite(trigpin1,LOW);
//  
//  delayMicroseconds(2);
//  
//  
//  digitalWrite(trigpin1,HIGH);
//
//  
//  delayMicroseconds(5);
//  
//  digitalWrite(trigpin1,LOW);
//
//  
//  time1 = pulseIn(echopin1,HIGH);
//  cm1 = (time1/58.82);
//  
//
//  Serial.print("S1: ");
//  Serial.print(cm1);
//  Serial.println(" cm.");
//  
//  if (cm1<5){
//   digitalWrite(buzzer,HIGH); 
//  }
//  else{
//    digitalWrite(buzzer,LOW);
//  }
//}
