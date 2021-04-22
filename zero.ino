#include <Servo.h>
#include<SoftwareSerial.h>
SoftwareSerial bluetooth(12,13);
Servo servox;
Servo servoy;
Servo servoz;
Servo servog;
void arm()
{ servox.write(60);
  servoy.write(180);
  servoz.write(50);
  servog.write(0);
  delay(1000);
 
  
}
void setup() {
  // put your setup code here, to run once:
  servox.attach(7);
  servoy.attach(6);
  servoz.attach(5);
  servog.attach(4);
  arm();
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if (bluetooth.available()>=2)
{
  servox.detach();
  servoy.detach();
  servoz.detach();
  servog.detach();
  unsigned int servopos=bluetooth.read();
  unsigned int servopos1=bluetooth.read();
  
unsigned int realservo= (servopos1*256)+servopos;
Serial.println(realservo);
int servo1=realservo;
Servo currservo;

if (realservo>=1000 && realservo<1180){
  servox.attach(7);
  servo1=map(servo1,1000,1180,0,180);
  currservo=servox;
}
if (realservo>=2000 && realservo<2180){
  servoy.attach(6);
  servo1=map(servo1,2000,2180,0,180);
  currservo=servoy;}
  if (realservo>=3000 && realservo<3180){
  servoz.attach(5);
  servo1=map(servo1,3000,3180,0,180);
  currservo=servoz;}
  if (realservo>=4000 && realservo<4180){
  servog.attach(4);
  servo1=map(servo1,4000,4180,0,180);
  currservo=servog;}
currservo.write(servo1);
}
}
