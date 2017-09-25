#include<SoftwareSerial.h>

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

SoftwareSerial BT(10,11); //RX,TX

void setup() {
  // put your setup code here, to run once:
pinMode(M1P1,OUTPUT);
pinMode(M1P2,OUTPUT);
pinMode(M2P1,OUTPUT);
pinMode(M2P2,OUTPUT);
pinMode(EN1,OUTPUT);
pinMode(EN2,OUTPUT);
Serial.begin(9600);
BT.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
char a;
    String str;
    while(BT.available()) //Check if there is an available byte to read
    {
      a=BT.read();  //Conduct a serial read
      delay(10);  //Delay added to make thing stable
      str += a; //Shortcut concatenating a word: str = str + a
    }

  
    if(str.length()>0)
    {
      Serial.println(str);
    }
  
   if(str=="*Jarvis advance#" || str=="*move forward#")
    {
      forward();
      Serial.println("straight");
      delay(700);
      freeze();
    }
    else if(str=="*Jarvis retreat#" || str=="*move reverseward#")
    {
      reverse();
      Serial.println("reverse");
      delay(700);
      freeze();
    }
    else if(str=="*Jarvis alert#" || str=="*freeze#")
    {
      freeze();
      Serial.println("stop");
    }
    else if(str=="*turn left#")
    {
      left();
      Serial.println("left");
      delay(300);
      freeze();
    }
    else if(str=="*turn right#")
    {
      right();
      Serial.println("right");
      delay(300);
      freeze();
    }
    else
    {
      freeze();
    }

    str=""; //Reset the variable after initiating
    
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
