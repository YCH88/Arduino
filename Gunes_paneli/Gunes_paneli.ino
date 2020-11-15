#include <Servo.h>

Servo x, y;

int maks = 0;
int mx = 90;
int my = 90;

void setup() {
  Serial.begin(9600);
  x.attach(8);
  y.attach(9);

  x.write(90);
  y.write(90);
}

void Tara()
{
  for (int i = 0; i < 180; i += 30)
  {
    x.write(i);
    Serial.println(maks);
    for (int j = 30; j < 180; j++)
    {
      if (maks < analogRead(A0) && j!=31 && j!=32 && j!=33)
      {
        Serial.print("\nmaks:");
        Serial.print(maks);
        Serial.print("\nmx:");
        Serial.print(mx);
        Serial.print("\nmy:");
        Serial.print(my);
        Serial.println("");
        delay(20);
        mx = i;
        my = j;
        maks = analogRead(A0);
        delay(20);
      }
      y.write(j);
      delay(20);
    }
  }

}
void loop() {

  x.write(mx);
  y.write(my);
  delay(1000);
  Serial.println(analogRead(A0) + "\n");
  if (maks + 200 < analogRead(A0) || maks - 200 > analogRead(A0))
  {
    maks = 0;
    Tara();
  }
  Serial.print("\nmaks:");
  Serial.print(maks);
  Serial.print("\nmx:");
  Serial.print(mx);
  Serial.print("\nmy:");
  Serial.print(my);
  Serial.println("");
}
