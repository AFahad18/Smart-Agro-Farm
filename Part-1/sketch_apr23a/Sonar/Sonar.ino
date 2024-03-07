int trig = 8;
int echo = 9;
int buzzer = 11;
float cm;
float time;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig,LOW);
  
  time = pulseIn(echo,HIGH);
  cm = time/58.82;
  
  Serial.print("Distance: ");
  Serial.println(cm);
//  if(cm<10)
//  {
//    digitalWrite(buzzer,HIGH);
//  }
//  
//  else{
//    digitalWrite(buzzer,LOW);
//  }
  delay(1000);

}
