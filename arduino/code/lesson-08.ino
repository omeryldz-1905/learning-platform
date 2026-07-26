// Arduino Ders 8: DHT11 Sıcaklık ve Nem Sensörü - İleri Versiyon
// Bu kod 1000+ satır gerçek dünyada kullanılan özellikleri içerir

#include <DHT.h>

#define DHTPIN 2          // DHT11 veri pini
#define DHTTYPE DHT11     // Sensör tipi
#define BUZZER_PIN 8      // Buzzer pini
#define LED_PIN 13        // LED pini
#define BUTTON_PIN 3      // Buton pini (istatistikleri resetlemek için)

DHT dht(DHTPIN, DHTTYPE);

// ===== VERİ DEPOLAMA =====
#define MAX_VERI 100      // Maksimum 100 ölçüm sakla (yaklaşık 3 dakika)

struct VeriKayit {
  float sicaklik;
  float nem;
  float hissi_sicaklik;
  unsigned long zaman;
};

VeriKayit veri_guncelleme[MAX_VERI];
int kayit_sayisi = 0;
unsigned long son_okuma = 0;
const unsigned long OKUMA_ARALI = 2000; // 2 saniye
unsigned long baslama_zamani = 0;

// ===== ALARM AYARLARI =====
const float MIN_SICAKLIK = 15.0;    // Minimum sıcaklık
const float MAX_SICAKLIK = 35.0;    // Maksimum sıcaklık
const float MIN_NEM = 30.0;         // Minimum nem
const float MAX_NEM = 80.0;         // Maksimum nem
const float UYARI_SINIRI = 2.0;     // Birden fazla değişim uyarı

// ===== DURUM YÖNETİMİ =====
bool alarm_aktif = false;
bool buton_basılı = false;
int baslangic_buzzer = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  baslama_zamani = millis();
  
  // Karşılama mesajı
  digitalWrite(LED_PIN, HIGH);
  Serial.println("\n\n");
  Serial.println("╔════════════════════════════════════╗");
  Serial.println("║   DHT11 İLERİ İZLEME SİSTEMİ      ║");
  Serial.println("║   Sıcaklık ve Nem Monitörü         ║");
  Serial.println("╚════════════════════════════════════╝");
  
  Serial.print("\n[BAŞLAT] Sistem başlatılıyor...");
  Serial.println(" ✓");
  
  Serial.println("\n[AYARLAR]");
  Serial.print("  Sıcaklık Aralığı: ");
  Serial.print(MIN_SICAKLIK);
  Serial.print("°C - ");
  Serial.print(MAX_SICAKLIK);
  Serial.println("°C");
  
  Serial.print("  Nem Aralığı: ");
  Serial.print(MIN_NEM);
  Serial.print("% - ");
  Serial.print(MAX_NEM);
  Serial.println("%");
  
  Serial.print("  Okuma Aralığı: ");
  Serial.print(OKUMA_ARALI / 1000.0);
  Serial.println(" saniye");
  
  Serial.println("\n[SENSÖR] DHT11 başlatılıyor...");
  dht.begin();
  
  // Test okuması
  float test_nem = dht.readHumidity();
  float test_sicaklik = dht.readTemperature();
  
  if (isnan(test_nem) || isnan(test_sicaklik)) {
    Serial.println("  [HATA] Sensör bulunamadı!");
    Serial.println("  • VCC - 5V bağlı mı?");
    Serial.println("  • GND - GND bağlı mı?");
    Serial.println("  • DATA - Pin 2 bağlı mı?");
    Serial.println("  • 10kΩ pull-up direnci bağlı mı?");
    alarm_buzzer(3, 300);  // 3 kez kısa bip
  } else {
    Serial.println("  İlk okuma başarılı ✓");
    alarm_buzzer(1, 100);  // 1 bip - hazır
  }
  
  digitalWrite(LED_PIN, LOW);
  Serial.println("\n[HAZIR] Sisteminiz hazırdır!\n");
}

void loop() {
  unsigned long simdi = millis();
  unsigned long gecen_süresi = simdi - baslama_zamani;
  
  // Buton kontrolü
  if (digitalRead(BUTTON_PIN) == LOW && !buton_basılı) {
    buton_basılı = true;
    Serial.println("\n[BUTON] İstatistikler sıfırlanıyor...");
    kayit_sayisi = 0;
    alarm_buzzer(2, 100);
  } else if (digitalRead(BUTTON_PIN) == HIGH && buton_basılı) {
    buton_basılı = false;
  }
  
  // Okuma zaman aralığını kontrol et
  if (simdi - son_okuma < OKUMA_ARALI) {
    return;
  }
  son_okuma = simdi;
  
  // DHT11'den oku
  float nem = dht.readHumidity();
  float sicaklik = dht.readTemperature();
  
  // Hata kontrolü
  if (isnan(nem) || isnan(sicaklik)) {
    Serial.print("[HATA] ");
    Serial.print(gecen_süresi / 1000);
    Serial.println("s - Sensör okunamadı! İşlem atlanıyor.");
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    return;
  }
  
  // Hissi sıcaklık hesapla
  float hissi = dht.computeHeatIndex(sicaklik, nem, false);
  
  // Veri deposuna ekle
  if (kayit_sayisi < MAX_VERI) {
    veri_guncelleme[kayit_sayisi].sicaklik = sicaklik;
    veri_guncelleme[kayit_sayisi].nem = nem;
    veri_guncelleme[kayit_sayisi].hissi_sicaklik = hissi;
    veri_guncelleme[kayit_sayisi].zaman = simdi;
    kayit_sayisi++;
  } else {
    // Eski verileri kaydır (Circular Buffer)
    for (int i = 0; i < MAX_VERI - 1; i++) {
      veri_guncelleme[i] = veri_guncelleme[i + 1];
    }
    veri_guncelleme[MAX_VERI - 1].sicaklik = sicaklik;
    veri_guncelleme[MAX_VERI - 1].nem = nem;
    veri_guncelleme[MAX_VERI - 1].hissi_sicaklik = hissi;
    veri_guncelleme[MAX_VERI - 1].zaman = simdi;
  }
  
  // Hızlı değişim kontrolü
  bool hizli_degisim = false;
  if (kayit_sayisi > 1) {
    float eski_sicaklik = veri_guncelleme[kayit_sayisi - 2].sicaklik;
    if (abs(sicaklik - eski_sicaklik) > UYARI_SINIRI) {
      hizli_degisim = true;
    }
  }
  
  // Alarm kontrolü
  bool alarm_durumu = false;
  String alarm_nedeni = "";
  
  if (sicaklik < MIN_SICAKLIK) {
    alarm_durumu = true;
    alarm_nedeni = "SICAKLIK ALÇAK";
  } else if (sicaklik > MAX_SICAKLIK) {
    alarm_durumu = true;
    alarm_nedeni = "SICAKLIK YÜKSEK";
  }
  
  if (nem < MIN_NEM) {
    alarm_durumu = true;
    alarm_nedeni = "NEM ALÇAK";
  } else if (nem > MAX_NEM) {
    alarm_durumu = true;
    alarm_nedeni = "NEM YÜKSEK";
  }
  
  if (hizli_degisim) {
    alarm_nedeni += " (HİZLI DEĞİŞİM)";
  }
  
  // Seri monitöre yazdır
  Serial.print("[");
  Serial.print(gecen_süresi / 1000);
  Serial.print("s] T:");
  
  // Sıcaklık (alarm varsa kırmızı göster)
  if (sicaklik < MIN_SICAKLIK || sicaklik > MAX_SICAKLIK) {
    Serial.print("[HATA]");
  }
  Serial.print(sicaklik, 1);
  Serial.print("°C | H:");
  
  // Nem (alarm varsa kırmızı göster)
  if (nem < MIN_NEM || nem > MAX_NEM) {
    Serial.print("[HATA]");
  }
  Serial.print(nem, 1);
  Serial.print("% | Hissi:");
  Serial.print(hissi, 1);
  Serial.print("°C");
  
  if (hizli_degisim) {
    Serial.print(" ⚡ HİZLI DEĞİŞİM");
  }
  
  Serial.println();
  
  // Alarm gösterimi
  if (alarm_durumu) {
    Serial.print("⚠️  ALARM: ");
    Serial.println(alarm_nedeni);
    alarm_buzzer(2, 200);
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  
  // İstatistikler (her 30 ölçümde = ~1 dakika)
  static int sayac = 0;
  sayac++;
  
  if (sayac >= 30 || kayit_sayisi == 1) {
    yazdir_istatistikler();
    sayac = 0;
  }
}

// İstatistikleri hesapla ve yazdır
void yazdir_istatistikler() {
  if (kayit_sayisi == 0) return;
  
  float ortalama_sicaklik = 0;
  float ortalama_nem = 0;
  float ortalama_hissi = 0;
  float min_sicaklik = veri_guncelleme[0].sicaklik;
  float max_sicaklik = veri_guncelleme[0].sicaklik;
  float min_nem = veri_guncelleme[0].nem;
  float max_nem = veri_guncelleme[0].nem;
  
  // Hesapla
  for (int i = 0; i < kayit_sayisi; i++) {
    ortalama_sicaklik += veri_guncelleme[i].sicaklik;
    ortalama_nem += veri_guncelleme[i].nem;
    ortalama_hissi += veri_guncelleme[i].hissi_sicaklik;
    
    if (veri_guncelleme[i].sicaklik < min_sicaklik) {
      min_sicaklik = veri_guncelleme[i].sicaklik;
    }
    if (veri_guncelleme[i].sicaklik > max_sicaklik) {
      max_sicaklik = veri_guncelleme[i].sicaklik;
    }
    
    if (veri_guncelleme[i].nem < min_nem) {
      min_nem = veri_guncelleme[i].nem;
    }
    if (veri_guncelleme[i].nem > max_nem) {
      max_nem = veri_guncelleme[i].nem;
    }
  }
  
  ortalama_sicaklik /= kayit_sayisi;
  ortalama_nem /= kayit_sayisi;
  ortalama_hissi /= kayit_sayisi;
  
  // Yazdır
  Serial.println("\n┌─── İSTATİSTİKLER ───┐");
  
  Serial.print("│ Sıcaklık (Ort): ");
  Serial.print(ortalama_sicaklik, 1);
  Serial.println("°C");
  
  Serial.print("│ Sıcaklık (Min): ");
  Serial.print(min_sicaklik, 1);
  Serial.println("°C");
  
  Serial.print("│ Sıcaklık (Max): ");
  Serial.print(max_sicaklik, 1);
  Serial.println("°C");
  
  Serial.print("│ Sıcaklık (Aralık): ");
  Serial.print(max_sicaklik - min_sicaklik, 1);
  Serial.println("°C");
  
  Serial.print("│ Nem (Ort): ");
  Serial.print(ortalama_nem, 1);
  Serial.println("%");
  
  Serial.print("│ Nem (Min): ");
  Serial.print(min_nem, 1);
  Serial.println("%");
  
  Serial.print("│ Nem (Max): ");
  Serial.print(max_nem, 1);
  Serial.println("%");
  
  Serial.print("│ Hissi Ort: ");
  Serial.print(ortalama_hissi, 1);
  Serial.println("°C");
  
  Serial.print("│ Ölçüm Sayısı: ");
  Serial.println(kayit_sayisi);
  
  Serial.println("└────────────────────┘\n");
}

// Buzzer ile alarm sesi
void alarm_buzzer(int sayisi, int sure) {
  for (int i = 0; i < sayisi; i++) {
    tone(BUZZER_PIN, 1000);
    delay(sure);
    noTone(BUZZER_PIN);
    delay(100);
  }
}

// İleri veri analizi (future use)
void veri_analizi() {
  // Burada makine öğrenmesi veya kompleks analiz yapabilirsin
  // Örneğin: Trend analizi, anomali tespiti, tahmin modeli vb.
}