// Potansiyometre ile LED Parlaklığı - Ders 5

int potPin = A0;        // Potansiyometre - Analog Pin 0
int ledPin = 9;         // LED - PWM Pin
int potValue = 0;       // Potansiyometre değeri (0-1023)
int ledBrightness = 0;  // LED parlaklığı (0-255)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // Seri iletişim başlat (hata ayıklama için)
}

void loop() {
  // Potansiyometreden analog değer oku (0-1023)
  potValue = analogRead(potPin);
  
  // 0-1023 değerini 0-255'e dönüştür (map fonksiyonu)
  ledBrightness = map(potValue, 0, 1023, 0, 255);
  
  // LED parlaklığını ayarla
  analogWrite(ledPin, ledBrightness);
  
  // Seri monitöre yazdır (isteğe bağlı)
  Serial.print("Potansiyometre: ");
  Serial.print(potValue);
  Serial.print(" -> LED: ");
  Serial.println(ledBrightness);
  
  delay(100);
}