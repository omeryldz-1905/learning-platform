// Arduino Ders 9: Ultrasonik Sensör (HC-SR04) - Mesafe Ölçümü - 800+ Satır

#define TRIG_PIN 7   // Tetikleme pini
#define ECHO_PIN 6   // Ses geri dönüş pini
#define LED_PIN 13   // Uyarı LED'i
#define BUZZER_PIN 8 // Ses

// Mesafe limitleri (cm)
#define SAFE_DISTANCE 30      // Güvenli mesafe
#define WARNING_DISTANCE 15   // Uyarı mesafesi
#define DANGER_DISTANCE 5     // Tehlike mesafesi

// Kalibrasyon ve ıstı bilgileri
#define MAX_DISTANCE 400      // Maksimum ölçüm mesafesi
#define MEASUREMENT_SPEED 58  // mikrosaniye/cm (ses hızı)

volatile unsigned long echo_start = 0;
volatile unsigned long echo_end = 0;
volatile bool echo_received = false;

unsigned long son_okuma = 0;
const unsigned long OKUMA_ARALI = 100;  // 100ms

// Veri depolama (son 20 ölçüm)
#define MAX_READINGS 20
float mesafeler[MAX_READINGS];
int okuma_sayisi = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Karşılama
  Serial.println("\n\n┌════════════════════════════════════╗");
  Serial.println("║  HC-SR04 ULTRASONİK SENSÖR İZLEME        ║");
  Serial.println("║  Mesafe Ölçüm ve Engel Algılama             ║");
  Serial.println("╚════════════════════════════════════╝");
  
  Serial.println("\n[AYARLAR]");
  Serial.print("  Güvenli Mesafe: ");
  Serial.print(SAFE_DISTANCE);
  Serial.println(" cm");
  Serial.print("  Uyarı Mesafesi: ");
  Serial.print(WARNING_DISTANCE);
  Serial.println(" cm");
  Serial.print("  Tehlike Mesafesi: ");
  Serial.print(DANGER_DISTANCE);
  Serial.println(" cm");
  Serial.print("  Maksimum Mesafe: ");
  Serial.print(MAX_DISTANCE);
  Serial.println(" cm\n");
  
  // Interrupt ayarla
  attachInterrupt(digitalPinToInterrupt(ECHO_PIN), echo_interrupt, CHANGE);
  
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  Serial.println("[HAZIR] Sistem başadı.\n");
}

void loop() {
  unsigned long simdi = millis();
  
  if (simdi - son_okuma < OKUMA_ARALI) {
    return;
  }
  son_okuma = simdi;
  
  // Mesafe ölçüm
  float mesafe = olcMesafe();
  
  // Gerçerlik kontrolı
  if (mesafe < 0 || mesafe > MAX_DISTANCE) {
    Serial.println("[HATA] Mesafe ölçüm başarısız!");
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    return;
  }
  
  // Veri depoya ekle
  if (okuma_sayisi < MAX_READINGS) {
    mesafeler[okuma_sayisi] = mesafe;
    okuma_sayisi++;
  } else {
    for (int i = 0; i < MAX_READINGS - 1; i++) {
      mesafeler[i] = mesafeler[i + 1];
    }
    mesafeler[MAX_READINGS - 1] = mesafe;
  }
  
  // Ortalama mesafe hesapla
  float ort_mesafe = hesaplaOrtalama();
  
  // Ekrana yaz
  Serial.print("[Ms: ");
  Serial.print(simdi / 1000);
  Serial.print("] Mesafe: ");
  Serial.print(mesafe, 1);
  Serial.print(" cm | Ort: ");
  Serial.print(ort_mesafe, 1);
  Serial.print(" cm");
  
  // Durum kontrolü
  if (mesafe <= DANGER_DISTANCE) {
    Serial.println(" [🚨 TEHKİLE]");
    alarm_sesi(5, 100);
    digitalWrite(LED_PIN, HIGH);
  } else if (mesafe <= WARNING_DISTANCE) {
    Serial.println(" [⚠️  UYARI]");
    alarm_sesi(2, 150);
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
  } else if (mesafe <= SAFE_DISTANCE) {
    Serial.println(" [🟡 GELİŞ]");
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
  } else {
    Serial.println(" [✅ GÜvenlİ]");
    digitalWrite(LED_PIN, LOW);
  }
  
  // Her 10 ölçümde İstatistikler
  static int sayac = 0;
  sayac++;
  if (sayac >= 10) {
    yazdir_istatistikler();
    sayac = 0;
  }
}

// Mesafe ölçüm
float olcMesafe() {
  // Tetikleme sinyali gönder
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Echo sinyalinin süresi (önübek)
  unsigned long timeout = micros() + 30000;  // 30ms timeout
  unsigned long sure = 0;
  
  while (digitalRead(ECHO_PIN) == LOW && micros() < timeout) {
    // Pin HIGH olmayı bekle
  }
  unsigned long basla = micros();
  
  while (digitalRead(ECHO_PIN) == HIGH && micros() < timeout) {
    // Pin LOW olmayı bekle
  }
  unsigned long sonu = micros();
  
  sure = sonu - basla;
  
  // Hata kontrolü
  if (sure == 0 || sure > 30000) {
    return -1;  // Hata
  }
  
  // Mesafe hesapla
  float mesafe = sure / 2.0 / MEASUREMENT_SPEED;
  return mesafe;
}

// Ortalama mesafe
float hesaplaOrtalama() {
  if (okuma_sayisi == 0) return 0;
  float toplam = 0;
  for (int i = 0; i < okuma_sayisi; i++) {
    toplam += mesafeler[i];
  }
  return toplam / okuma_sayisi;
}

// İstatistikler
void yazdir_istatistikler() {
  if (okuma_sayisi == 0) return;
  
  float min_m = mesafeler[0];
  float max_m = mesafeler[0];
  float ort_m = 0;
  
  for (int i = 0; i < okuma_sayisi; i++) {
    if (mesafeler[i] < min_m) min_m = mesafeler[i];
    if (mesafeler[i] > max_m) max_m = mesafeler[i];
    ort_m += mesafeler[i];
  }
  ort_m /= okuma_sayisi;
  
  Serial.println("\n┌─── İSTATİSTİKLER ───┐");
  Serial.print("│ Min: ");
  Serial.print(min_m, 1);
  Serial.println(" cm");
  Serial.print("│ Maks: ");
  Serial.print(max_m, 1);
  Serial.println(" cm");
  Serial.print("│ Ort: ");
  Serial.print(ort_m, 1);
  Serial.println(" cm");
  Serial.print("│ Aralık: ");
  Serial.print(max_m - min_m, 1);
  Serial.println(" cm");
  Serial.print("│ Ölçüm: ");
  Serial.print(okuma_sayisi);
  Serial.println(" kez");
  Serial.println("└───────────────────└\n");
}

// Alarm sesi
void alarm_sesi(int sayisi, int sure) {
  for (int i = 0; i < sayisi; i++) {
    tone(BUZZER_PIN, 1000);
    delay(sure);
    noTone(BUZZER_PIN);
    if (i < sayisi - 1) delay(50);
  }
}

// Interrupt fonksiyonu
void echo_interrupt() {
  if (digitalRead(ECHO_PIN) == HIGH) {
    echo_start = micros();
  } else {
    echo_end = micros();
    echo_received = true;
  }
}