#include <SoftwareSerial.h>

SoftwareSerial sms(10,11);

String message;

int pH_value;
int voltagepin = A0;
int value = 0;

void setup() {
  Serial.begin(9600);
  sms.begin(9600);

}

void loop() {
  
  value = analogRead(voltagepin);
  float voltage = value * (5.0/1023.0);
  Serial.println(voltage);
  delay(1000);
  
  if(voltage == 4.14){
    pH_value = 0;
  }
  else if(voltage == 3.54){
    pH_value = 1;
  }
  else if(voltage == 2.95){
    pH_value = 2;
  }
  else if(voltage == 2.36){
    pH_value = 3;
  }
  else if(voltage == 1.77){
    pH_value = 4;
  }
  else if(voltage == 1.18){
    pH_value = 5;
  }
  else if(voltage == 0.59){
    pH_value = 6;
  }
  else if(voltage == 0){
    pH_value = 7;
  }
   else if(voltage == -0.59){
    pH_value = 8;
  }
  else if(voltage == -1.18){
    pH_value = 9;
  }
   else if(voltage == -1.77){
    pH_value = 10;
  }
  else if(voltage == -2.36){
    pH_value = 11;
  }
  else if(voltage == -2.95){
    pH_value = 12;
  }
  else if(voltage == -3.54){
    pH_value = 13;
  }
  if(voltage == -4.14){
    pH_value = 14;
  }
  Serial.println("1");
  
  sendsms();
  delay(30000);
  

}

void sendsms() {
  Serial.println("2");
  sms.println("AT+CMGF=1\r");
  delay(100);
  if(sms.find("OK")){
    Serial.println("ok");
  }
  sms.println("AT+CMGS=\"+94719248432\"\r");
  delay(500);
  if(sms.available()){
    Serial.write(sms.read());
  }
  if (pH_value < 3 || pH_value > 8){
  message = "Please feed me some nutritions...";
  }
  else if (pH_value >= 3.4 && pH_value <= 3.6 ){
    message = "I have all the nutritions...";
  }
  else if(pH_value >= 7.5 && pH_value<= 7.8){
    message = "I have enough UREA";
  }
  else if(pH_value >= 3.2 && pH_value<= 3.4){
    message = "I have enough TSP";
  }
  else if(pH_value >= 6.7 && pH_value<= 7.1){
    message = "I have enough MOP";
  }
   sms.println(message);        
  delay(100);
  sms.println((char)26);                       
  delay(100); 
  sms.println();
  delay(2000); 
    if(sms.available()){
    Serial.write(sms.read());
  }
  
}
