#include <LiquidCrystal.h>
#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
int DHT11_pin = 7; // DHT11_pin olarak Dijital 2'yi belirliyoruz.
dht11 DHT11_sensor; // DHT11_sensor adında bir DHT11 nesnesi oluşturduk.
int esikDegeri = 888;
int buzzerPin = 9;
int gaz = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int deger = analogRead(A0);
void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  lcd.begin(16, 2);
  delay(100);
  lcd.clear();
}

void loop() {
  int chk = DHT11_sensor.read(DHT11_pin);
  int isi = (((float)DHT11_sensor.temperature));
  deger = analogRead(A0);
  if (deger != analogRead(A0) || isi != ((DHT11_sensor.temperature)))
  { 
    lcd.print("Sicaklik=");
    lcd.print(isi);
    lcd.print((char)223);
    lcd.setCursor(0, 1);
    lcd.print("Sivi:");
    lcd.print(deger);
    lcd.print("/720");
    lcd.setCursor(16, 1);
    lcd.clear();
  }
  else
  {

    lcd.print("Sicaklik="); lcd.print(isi);
    lcd.print((char)223);
    lcd.setCursor(0, 1);
    lcd.print("Sivi:");
    lcd.print(deger);
    lcd.print("/720");
    lcd.setCursor(17, 1);
    
  }
  gaz = analogRead(A1);           //Sensörden analog değer okuyoruz.
  if (gaz > esikDegeri) {         //Sensörden okunan değer eşik değerinden büyükse çalışır.
    digitalWrite(buzzerPin, LOW);
  }
  else {                            //Sensörden okunan değer eşik değerinin altındaysa çalışır.
    digitalWrite(buzzerPin, LOW);
    delay(100);
    digitalWrite(buzzerPin, HIGH);
    delay(100);
  }

}
