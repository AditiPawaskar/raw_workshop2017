#define A 2
#define B 3
#define C 4
#define D 5
//#define S 6

int a;
int b;
int c;
int d;
int decimal;
void setup() {
  // put your setup code here, to run once:
pinMode(A,INPUT);
pinMode(B,INPUT);
pinMode(C,INPUT);
pinMode(D,INPUT);
//pinMode(S,INPUT);
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
}
