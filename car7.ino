/* Bluetooth */
#include <SoftwareSerial.h>
#define RxD 3
#define TxD 2
int r_motor_n = 10;  //PWM control Right Motor -
int r_motor_p = 11;  //PWM control Right Motor +
int l_motor_p = 5;   //PWM control Left Motor +
int l_motor_n = 6;
SoftwareSerial slave(RxD, TxD);
char message;
int motorvalue = 0;



void setup()
{
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(r_motor_n, OUTPUT);  //Set control pins to be outputs
  pinMode(r_motor_p, OUTPUT);
  pinMode(l_motor_p, OUTPUT);
  pinMode(l_motor_n, OUTPUT);

  digitalWrite(r_motor_n, LOW);  //set both motors off for start-up
  digitalWrite(r_motor_p, LOW);
  digitalWrite(l_motor_p, LOW);
  digitalWrite(l_motor_n, LOW);

  slave.begin(9600);
  Serial.begin(9600);
}



void loop()
{
  if (slave.available())
  {
    message = slave.read();
  }
  if (message == 'b')
    motorvalue = 1;
  if (message == 'n')
    motorvalue = 2;
  if (message == 'f')
    motorvalue = 3;
  if (message == 'r')
    motorvalue = 4;
  if (message == 'l')
    motorvalue = 5;


  switch (motorvalue)
  {
    case 2: //none
      digitalWrite(r_motor_n, LOW);  //Set motor direction, 1 low, 2 high
      digitalWrite(r_motor_p, LOW);
      digitalWrite(l_motor_p, LOW);
      digitalWrite(l_motor_n, LOW);
      Serial.println("Stop\n");
      //incomingByte='*';

      break;

    case 1: //backward
      analogWrite(r_motor_p,247 ); //Set motor direction, 1 low, 2 high
      analogWrite(r_motor_n, 190);
      analogWrite(l_motor_n, 255);
      analogWrite(l_motor_p, 190);
      Serial.println("Forward\n");
      //incomingByte='*';
      break;

    case 3: //forward
      analogWrite(r_motor_p, 190);  //Set motor direction, 1 low, 2 high
      analogWrite(r_motor_n,247);
      analogWrite(l_motor_n, 190);
      analogWrite(l_motor_p,255);
      Serial.println("Backward\n");
      //incomingByte='*';
      break;//}

    //switch(turnvalue){
    case 4: //right
      analogWrite(l_motor_n, 190);  //Set motor direction, 1 low, 2 high
      analogWrite(l_motor_p, 190);
     analogWrite(r_motor_n, 255);
      analogWrite(r_motor_p, 190);
      Serial.println("Rotate Right\n");
      break;


    case 5: //left
      analogWrite(l_motor_p, 255);  //Set motor direction, 1 low, 2 high
      analogWrite(l_motor_n, 190);
      analogWrite(r_motor_p, 190);
      analogWrite(r_motor_n, 190);
      Serial.println("Rotate Left\n");
      //incomingByte='*';
      break;
  }
}
