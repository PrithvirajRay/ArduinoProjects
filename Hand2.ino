/* accelerometer */
int Xpin = 4;
int Ypin = 5;
int accX, accY;
String motor; // forward/backward/none
String turn; // left/right/none

/* Bluetooth */
#include <SoftwareSerial.h>
#define RxD 2
#define TxD 3
SoftwareSerial master(RxD, TxD);



void setup()
{
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);

  master.begin(9600);
  Serial.begin(9600);
}



void loop()
{
  /* accelerometer */
  int Xread = pulseIn(Xpin, HIGH);
  int Yread = pulseIn(Ypin, HIGH); //read pulse widths
  accX = ((Xread/10) - 500)*8;
  accY = ((Yread/10) - 500)*8; //convert to milli-g, -1000~1000

  if (accX < -300) motor = "f";
  else if (accX > 300) motor = "b";
  else motor = "n";
  
  if (accY < -300) turn = "l";
  else if (accY > 300) turn = "r";
  else turn = "n";

  /* Bluetooth*/
  master.print(motor + '+' + turn); //send to slave as a string
  Serial.println(String(motor) + String(turn));
  delay(1000);
}
