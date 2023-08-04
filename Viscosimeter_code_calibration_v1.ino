/*
 You can calibrate this viscosimeter using a Newtonian fluids solutions with a known viscosity. For this viscosimeter we use a 
 Glycerol/water solutions. You can use this article "Segur, J. B., & Oberstar, H. E. (1951). Viscosity of glycerol and its aqueous solutions. 
 Industrial & Engineering Chemistry, 43(9), 2117-2120." In the file "Falling ball viscosimeter calibration method" are whole information
 about the calibration.

 The main idea of this code is use LEDs and photosensors array to measure the time between two points when the ball is falling"
 */


float I1=0;
float I2=0;
float I3=0;
float I4=0;
float t1=0;
float t2=0;
float t3=0;
float delta_t1=0;
float delta_t2=0;
float delta_T=0;
float v1=0;
float v2=0;
float tiempo=0;
float v_media=0;
float v_total=0;

#include "DHT.h"

#define DHTPIN 7    // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(7,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

I1 = analogRead(A0);
I2 = analogRead(A1);
I3 = analogRead(A2);

float t = dht.readTemperature(); 



 
while(0==0){

while (!(analogRead(A0)<I1-40)) {
  t1 = micros();
  
 
 
  }
 
while (!(analogRead(A1)<I2-40)) {
  t2 = micros();
  delta_t1 = (t2-t1)/1000000;
  
 v1=18/(delta_t1);
 
 
  }

while (!(analogRead(A2)<I3-40)) {
  t3 = micros();
  delta_t2 = (t3-t2)/1000000;
  delta_T=(t3-t1)/1000000;
  v2=(27)/(delta_t2);
  v_total=(45)/(delta_T);
  v_media=((v1+v2)/2);
  
 
 
  }

  Serial.print("velocity_1=");
  Serial.print(v1);
  Serial.print(",");
  Serial.print("[mm/s]");
  Serial.print("velocity_2=");
  Serial.print(v2);
  Serial.print("[mm/s]");
  Serial.print(",");
  Serial.print("Total_velocity=");
  Serial.print(v_total);
  Serial.print("[mm/s]");
  Serial.print(",");
  Serial.print("total_time=");
  Serial.print(delta_T,4);
  Serial.println("[s]");
  

  
  
}


}
