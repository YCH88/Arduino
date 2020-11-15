#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 5, 6, 7, 3, 2);

RF24 r(9, 10);
const uint64_t k = 0xE8E8F0F0E1LL;
int dizi[1];

void setup() {
  Serial.begin(9600);
  r.begin();
  r.openReadingPipe(1, k);
  r.startListening();
  lcd.begin (16, 2);
}
void loop() {
  if (r.available())
  {
    r.read(dizi, sizeof(dizi));
    Serial.println(dizi[0]);
    lcd.print("Kalp Atisi:");
    lcd.print((dizi[0]));
    lcd.print("bpm");
    
    delay(500);
    dizi[0] = 0;
  }
  else
  {
    Serial.println("YOK");
    lcd.print("YOK");
  }
  delay(100);
  lcd.clear();
}
