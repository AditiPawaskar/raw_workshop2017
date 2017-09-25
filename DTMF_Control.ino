#define A 2
#define B 3
#define C 4
#define D 5
//#define S 12
#define M1P1 6
#define M1P2 7
#define M2P1 8
#define M2P2 9
#define EN1 10
#define EN2 11


int a;
int b;
int c;
int d;
int decimal;

void forward();
void reverse();
void left();
void right();
void freeze();
void setup() {
  // put your setup code here, to run once:
pinMode(A,INPUT);
pinMode(B,INPUT);
pinMode(C,INPUT);
pinMode(D,INPUT);
//pinMode(S,INPUT);
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
a=digitalRead(A);
b=digitalRead(B);
c=digitalRead(C);
d=digitalRead(D);
decimal=(pow(2,3)*a)+(pow(2,2)*b)+(pow(2,1)*c)+(pow(2,0)*d);
Serial.println();
Serial.print("Value - ");
Serial.println(decimal);
delay(50);
switch(decimal)
{
    case 2:forward(); 
            delay(50);
            break;
    case 6:right(); 
            delay(50);
            break;
    case 4:left(); 
            delay(50);
            break;
    case 8:reverse(); 
            delay(50);
            break;
    case 5:freeze(); 
            delay(50);
            break;
       
}

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
