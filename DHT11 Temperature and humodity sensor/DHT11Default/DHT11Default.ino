#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

void setup() {
    // start working...
  
  Serial.begin(9600);
  Serial.println("Temp Data: ");
}

void loop() {
 
  
  
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
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}





//#include <dht.h>
//#define dht_apin 2 // Analog Pin sensor is connected to
// 
//dht DHT;
//
//
//
//void setup(){
// 
//  Serial.begin(9600);
//  delay(500);//Delay to let system boot
//  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
//  delay(1000);//Wait before accessing Sensor
// 
//}//end "setup()"
// 
//void loop(){
//  //Start of Program 
// 
//    DHT.read11(dht_apin);
//    
//    Serial.print("Current humidity = ");
//    Serial.print(DHT.humidity);
//    Serial.print("%  ");
//    Serial.print("temperature = ");
//    Serial.print(DHT.temperature); 
//    Serial.println("C  ");
//    
//    delay(500);//Wait 5 seconds before accessing sensor again.
// 
//  //Fastest should be once every two seconds.
// 
//}// end loop() 
