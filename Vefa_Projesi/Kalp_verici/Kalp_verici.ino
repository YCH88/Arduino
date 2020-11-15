#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS     1000

PulseOximeter pox;

uint32_t tsLastReport = 0;

int dizi[1];

RF24 r(9, 10);
const uint64_t k = 0xE8E8F0F0E1LL;

int sayac = 0;

void onBeatDetected()
{
  Serial.println("Beat!");
}

void setup() {
  Serial.begin(11500);
  r.begin();
  Wire.begin();
  r.openWritingPipe(k);
  Serial.print("Initializing pulse oximeter..");
  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }
  pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
  dizi[0] = pox.getHeartRate();
  r.write(dizi, sizeof(dizi));

  pox.update();
  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    Serial.print("Heart rate:");
    Serial.print(pox.getHeartRate());
    Serial.print("bpm / SpO2:");
    Serial.print(pox.getSpO2());
    Serial.println("%");
    dizi[0] = pox.getHeartRate();
    r.write(dizi, sizeof(dizi));
    Serial.println(dizi[0]);
    tsLastReport = millis();
  }
}
