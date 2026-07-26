// LDR Işık Sensörü - Ders 7

int ldrPin = A0;      // LDR Pin
int ledPin = 9;       // LED Pin
int lightValue = 0;   // Işık değeri
int threshold = 300;  // Eşik değeri

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // LDR'den analog değer oku
  lightValue = analogRead(ldrPin);
  
  // Işık şiddetine göre LED kontrol et
  if (lightValue < threshold) {
    // Karanlık - LED'i yak
    digitalWrite(ledPin, HIGH);
    Serial.println("Karanlık - LED YANDIRILDI");
  } else {
    // Aydınlık - LED'i söndür
    digitalWrite(ledPin, LOW);
    Serial.println("Aydınlık - LED SÖNDÜRÜLDÜ");
  }
  
  Serial.print("Işık Değeri: ");
  Serial.println(lightValue);
  Serial.println("---");
  
  delay(500);
}