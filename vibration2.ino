const int ledPin=13;
void setup() {
  Serial.begin(9600);
pinMode(ledPin,OUTPUT);
} 
 
void loop() {
int sensorValue = analogRead(A0);//read the vibration
 Serial.println(sensorValue);//print it
 delay(1000);
 if(sensorValue==1023)//if you have an led it will turn on or off based on the vibration
  {
    digitalWrite(ledPin,HIGH);
  }
 else
 {
  digitalWrite(ledPin,LOW);
  }
}
