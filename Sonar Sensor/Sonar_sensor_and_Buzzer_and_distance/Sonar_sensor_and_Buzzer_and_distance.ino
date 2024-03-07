int echopin1 = 2;
int trigpin1 = 6;

//int echopin2 = 5;
//int trigpin2 = 9;
//
//int echopin3 = 4;
//int trigpin3 = 7;
//
//int echopin4 = 2;
//int trigpin4 = 8;




int buzzer = 11;
float time1,time2,time3,time4;
float cm1,cm2,cm3,cm4;




void setup() {
  // put your setup code here, to run once:
  pinMode(trigpin1,OUTPUT);
  pinMode(echopin1,INPUT);
//  pinMode(trigpin2,OUTPUT);
//  pinMode(echopin2,INPUT);
//  pinMode(trigpin3,OUTPUT);
//  pinMode(echopin3,INPUT);
//  pinMode(trigpin4,OUTPUT);
//  pinMode(echopin4,INPUT);
//  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin1,LOW);
//  digitalWrite(trigpin2,LOW);
//  digitalWrite(trigpin3,LOW);
//  digitalWrite(trigpin4,LOW);
  
  delay(2);
  
  digitalWrite(trigpin1,HIGH);
//  digitalWrite(trigpin2,HIGH);
//  digitalWrite(trigpin3,HIGH);
//  digitalWrite(trigpin4,HIGH);
  
  delayMicroseconds(5);
  
  digitalWrite(trigpin1,LOW);
//  digitalWrite(trigpin2,LOW);
//  digitalWrite(trigpin3,LOW);
//  digitalWrite(trigpin4,LOW);
  
  time1 = pulseIn(echopin1,HIGH);
  cm1 = time1/58.82;
  
//  time2 = pulseIn(echopin2,HIGH);
//  cm2 = time2/58.82;
//  
//  time3 = pulseIn(echopin3,HIGH);
//  cm3 = time3/58.82;
//  
//  time4 = pulseIn(echopin4,HIGH);
//  cm4 = time4/58.82;
  //Serial.print("The Distance is ");
  Serial.print("S1: ");
  Serial.print(cm1);
  Serial.println(" cm.");
  
//   Serial.print("S2: ");
//  Serial.print(cm2);
//  Serial.println(" cm.");
//  
//   Serial.print("S3: ");
//  Serial.print(cm3);
//  Serial.println(" cm.");
//  
//   Serial.print("S4: ");
//  Serial.print(cm4);
//  Serial.println(" cm.");
  if (cm1<5){
   digitalWrite(buzzer,HIGH); 
  }
  else{
    digitalWrite(buzzer,LOW);
  }
}
