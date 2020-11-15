#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

int dizi[4];
int emsg ;
int eka ;
int nx = 0;
int ny = 0;
int ne = 0;
int nk = 0;

RF24 r(9, 10);
const uint64_t k = 0xE8E8F0F0E1LL;

const int in1 = 4;     // Motor sürücümüze bağladığımız pinleri tanımlıyoruz
const int in2 = 7;
const int in3 =  2;
const int in4 =  3;

const int enA = 5;  //Enable pinlerini arduino 5,6 pwm pinlerine bağladık.
const int enB = 6;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  Serial.begin(9600);
  r.begin();
  r.openReadingPipe(1, k);
  r.startListening();
}

void loop() {

  if (r.available())
  {
    bool done = false;

    r.read(dizi, sizeof(dizi));

    delay(100);
    hareket(dizi[0], dizi[1], dizi[2], dizi[3]);
  }
  else
    Serial.println("YOk");
  // put your main code here, to run repeatedly:
}
void hareket(int x, int y, int xi, int yi)
{
  nx = x;
  ny = y;
  if (!(x > -2 && x < 2) && x != y)
    ny = y;
  //BURALAR DİREK HIZ
  if (!(y > -2 && y < 2) && y != x)
    nx = x;

  //Yönün Algılanması
  if (xi > 0)
    ne = 1;
  else
    ne = 0;

  if (yi > 0)
    nk = 1;
  else
    nk = 0;


  {

  }

  if (ny > 60)
  {
    digitalWrite(in3, HIGH);
    digitalWrite(in1, HIGH);
    digitalWrite(in4,  LOW);
    digitalWrite(in2, LOW);
    analogWrite(enB,  255);
    analogWrite(enA, 255);
  }
  else
  {
    digitalWrite(in3, LOW);
    digitalWrite(in1, LOW);
    digitalWrite(in4,  LOW);
    digitalWrite(in2, LOW);
  }

  /* if (ne == 0 && ny > 10)
    {
     analogWrite(enA,  ny + 60 - nx / 2);
     analogWrite(enB, ny + 60);
    }
    else if (ne != 0 && ny > 10) {
     analogWrite(enB,  ny + 60 - nx / 2 );
     analogWrite(enA, ny + 60);
    }
  */

  Serial.print(nx);
  Serial.print("   ");
  Serial.print(ny);
  Serial.print("  ");
  Serial.print(ne);
  Serial.print("  ");
  Serial.print(nk);
  Serial.println("");

}



