#define R 8
#define G 9
#define B 11

void setup() {
  // put your setup code here, to run once:
pinMode(R,OUTPUT);
pinMode(G,OUTPUT);
pinMode(B,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(R,255);
delay(2000);
analogWrite(G,255);
delay(2000);
analogWrite(B,255);
delay(2000);
}
