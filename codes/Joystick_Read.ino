#define Xaxis A0
#define Yaxis A1 
int ValX=0;
int ValY=0;
void setup() {
  // put your setup code here, to run once:
pinMode(Xaxis, INPUT);
pinMode(Yaxis, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
ValX=analogRead(Xaxis);
Serial.print("ValX - ");
Serial.println(ValX);
ValY=analogRead(Yaxis);
Serial.print("ValY - ");
Serial.println(ValY);
delay(1000);
}
