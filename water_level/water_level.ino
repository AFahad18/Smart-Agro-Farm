int resval = 0;
int respin= A5;

void setup(){
  Serial.begin (9600);
}
void loop(){
  resval= analogRead(respin);
  if (resval<=100){
    Serial.println("Water Level Empty");
  }
  else if (resval>100 && resval<=300){
    Serial.println("Water Level Low");
  }
  else if (resval>300 && resval<=330){
    Serial.println("Water Level Medium");
  }
   else if (resval>330){
    Serial.println("Water Level High");
  }
  delay (1000);
  
}
