#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <MPU6050_tockn.h>
#include <Wire.h>
MPU6050 mpu6050(Wire);
int dizi[4];
int msg[1];
int emsg[1];

RF24 r(9, 10);
const uint64_t k = 0xE8E8F0F0E1LL;


void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  r.begin();
  r.openWritingPipe(k);
}

void loop() {
  mpu6050.update();
 dizi[2]=1;
 dizi[3]=1;
  dizi[0] = mpu6050.getAngleX();     // X  Y  X_işareti Y_işareti
  if (dizi[0] < 0)
  {
    dizi[2] = 0;
dizi[0]=-dizi[0];
  }
  dizi[1] = mpu6050.getAngleY();
  if (dizi[1] < 0)
  {
    dizi[3] = 0;
    dizi[1]=-dizi[1];
  }

  Serial.print(dizi[0]);
  Serial.print("  ");
  Serial.print(dizi[1]);
  Serial.print("  ");
  Serial.print(dizi[2]);
  Serial.print("   ");
  Serial.print(dizi[3]);
  Serial.println("");
  //Serial.println(" 1 Pozitif 0 Negatif");
  //Serial.println(ka[0]);
  
r.write(dizi, sizeof(dizi));

}
