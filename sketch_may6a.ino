// SerialMouse sketch
//#define potYPin 5
int vale = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int x = analogRead(A0);
  
  vale = map(x, 0, 1023, 100, 999);
  //int y = analogRead(potYPin);
  Serial.print(".");  //ascii = 46
  Serial.print(vale,DEC);
  Serial.print("/"); //ascii = 47
  //delay(50);
  //Serial.print(y,DEC);*/
  //Serial.println();  // send a cr/lf
  //delay(50); // send position 20 times a second
}