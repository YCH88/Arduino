#include <SoftwareSerial.h>
#include<Wire.h>
SoftwareSerial k(0, 1); //8 RX  9 TX

const int in1 = 4;     // Motor sürücümüze bağladığımız pinleri tanımlıyoruz
const int in2 = 7;
const int in3 =  2;
const int in4 =  3;

const int enA = 5;  //Enable pinlerini arduino 5,6 pwm pinlerine bağladık.
const int enB = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  k.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}



void loop() {
  // put your main code here, to run repeatedly:
    
analogWrite(enA,  255);
analogWrite(enB,  255);
   


  
  if (k.available())
  {
    char data = k.read();
    Serial.print(data);
    if (data == 'u') //3
{ 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    }
    if (data == 'r') {
digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    
    }
    if (data == 'l') //0
    {

digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    }
    if (data == 'd')
    {
 digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
    }

  }
}
