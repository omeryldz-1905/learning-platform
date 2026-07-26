// Arduino Ders 1: LED Yakıp Söndürme - Kod Dosyası

/*
 * ==========================================
 * ARDUINO LED YAKIP SÖNDÜRME PROJESİ
 * ==========================================
 * 
 * Bu program LED'i 1 saniye aralıklarla
 * yakıp söndürür.
 * 
 * Gerekli Malzemeler:
 * - Arduino Uno
 * - 1x LED (5mm, kırmızı)
 * - 1x 220Ω - 330Ω Direnç
 * - Jumper kablolar
 * 
 * Bağlantılar:
 * Arduino Pin 13 --[220Ω]--[LED anod]
 *                            [LED katod]--GND
 * 
 */

// setup() fonksiyonu: Program başlangıcında bir kez çalışır
void setup() {
  // Pin 13'ü OUTPUT (çıkış) olarak ayarla
  // Böylece pin'e HIGH (5V) veya LOW (0V) gönderebiliriz
  pinMode(13, OUTPUT);
  
  // Not: Arduino Uno'nın Pin 13'ü board üzerinde yerleşik LED'e bağlıdır
  // Bu nedenle harici LED olmadan bile test edebilirsiniz
}

// loop() fonksiyonu: Program bitene kadar sürekli tekrar eder
void loop() {
  // LED'i yak
  digitalWrite(13, HIGH);  // Pin 13'e HIGH (5V) gönder
  
  // 1000 milisaniye (1 saniye) bekle
  delay(1000);
  
  // LED'i söndür
  digitalWrite(13, LOW);   // Pin 13'e LOW (0V) gönder
  
  // 1000 milisaniye (1 saniye) bekle
  delay(1000);
  
  // Loop tekrar başlar ve işlem devam eder...
}

/*
 * ==========================================
 * KOD AÇIKLAMASI VE İPUÇLARIYUMLanma
 * ==========================================
 * 
 * digitalWrite(pin, value):
 * - pin: Hangi pin'e gönderileceği (13)
 * - value: HIGH (5V) veya LOW (0V)
 * 
 * delay(ms):
 * - Milisaniye cinsinden bekleme süresi
 * - 1000 ms = 1 saniye
 * - 500 ms = 0.5 saniye
 * 
 * ==========================================
 * DEĞİŞTİREBİLECEK ŞEYLER
 * ==========================================
 * 
 * 1. Yanıp Sönme Hızını Değiştir:
 *    delay(500);   // Daha hızlı
 *    delay(2000);  // Daha yavaş
 * 
 * 2. Farklı Pin Kullan:
 *    pinMode(10, OUTPUT);
 *    digitalWrite(10, HIGH);
 * 
 * 3. Asimetrik Yanıp Sönme:
 *    digitalWrite(13, HIGH);
 *    delay(300);
 *    digitalWrite(13, LOW);
 *    delay(700);
 * 
 * ==========================================
 */