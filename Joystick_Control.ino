#define Xaxis A0
#define Yaxis A1 

int x=0;
int y=0;
//M1-left motor
//M2-Right motor
#define M1P1 2
#define M1P2 4
#define M2P1 7
#define M2P2 8
#define EN1 5
#define EN2 6

void forward();
void reverse();
void left();
void right();
void freeze();
void setup() {
  // put your setup code here, to run once:
pinMode(Xaxis,INPUT);
pinMode(Yaxis,INPUT);
pinMode(M1P1,OUTPUT);
pinMode(M1P2,OUTPUT);
pinMode(M2P1,OUTPUT);
pinMode(M2P2,OUTPUT);
pinMode(EN1,OUTPUT);
pinMode(EN2,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
x=analogRead(x);
Serial.print("ValX - ");
Serial.println(x);
y=analogRead(y);
Serial.print("ValY - ");
Serial.println(y);

// check your values for default state
// if required make 450 -> 450 and 600 -> 650


if ( x < 100 &&  450<y<600){
  forward();
  delay(25);
  }
else if ( x > 900 &&  450<y<600){
  reverse();
  delay(25);
  }
else if ( y < 100 &&  450<x<600){
  right();
  delay(25);
  }
else if ( y > 900 &&  450<x<600){
  left();
  delay(25);
  }
else{
  freeze();
  delay(25);
  }
  delay(100);
}


void forward()
{
 Serial.println("FORWARD");
 analogWrite(EN1,255);
 analogWrite(EN2,255);
 digitalWrite(M1P1,HIGH);
 digitalWrite(M1P2,LOW);
 digitalWrite(M2P1,HIGH);
 digitalWrite(M2P2,LOW);
 }
 void reverse()
{
 Serial.println("REVERSE");
 analogWrite(EN1,255);
 analogWrite(EN2,255);
 digitalWrite(M1P1,LOW);
 digitalWrite(M1P2,HIGH);
 digitalWrite(M2P1,LOW);
 digitalWrite(M2P2,HIGH);
 }
 void left()
{
 Serial.println("LEFT");
 analogWrite(EN1,255);
 analogWrite(EN2,255);
 digitalWrite(M1P1,LOW);
 digitalWrite(M1P2,HIGH);
 digitalWrite(M2P1,HIGH);
 digitalWrite(M2P2,LOW);
 }
 void right()
{
 Serial.println("RIGHT");
 analogWrite(EN1,255);
 analogWrite(EN2,255);
 digitalWrite(M1P1,HIGH);
 digitalWrite(M1P2,LOW);
 digitalWrite(M2P1,LOW);
 digitalWrite(M2P2,HIGH);
 }
 void freeze()
{
 Serial.println("FREEZE");
 analogWrite(EN1,0);
 analogWrite(EN2,0);
 }
