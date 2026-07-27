// Arduino Ders 10: Servo Motor Kontrolü - 700+ Satır

#include <Servo.h>

Servo servo;          // Servo nesnesi
#define SERVO_PIN 9   // PWM pini
#define BUTTON_PIN 2  // Buton pini
#define POT_PIN A0    // Potansiyometre pini
#define LED_PIN 13    // LED pini

// Servo pozisyonlar
int pozisyon = 90;    // Orta konum
int hedef_pozisyon = 90;
int min_pozisyon = 0;
int max_pozisyon = 180;

// Kontrol modu
enum KontrolModu {
  MANUEL = 1,
  OTOMATIK = 2,
  POTANSIYOMETRE = 3
};

KontrolModu modu = MANUEL;
unsigned long son_okuma = 0;
const unsigned long OKUMA_ARALI = 50;  // 50ms

// Otomatik mod için
int otomatik_yonu = 1;  // 1 = ileri, -1 = geri
int otomatik_hiz = 2;   // Derece/adım

volatile int buton_basisi = 0;
unsigned long buton_zamani = 0;
const unsigned long DEBOUNCE = 200;  // 200ms

void setup() {
  Serial.begin(9600);
  
  servo.attach(SERVO_PIN);
  servo.write(pozisyon);
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.println("\n\n┌════════════════════════════════════╗");
  Serial.println("║  SERVO MOTOR KONTROL SİSTEMİ                 ║");
  Serial.println("║  3 Kontrol Modu - 180 Derece Hareket         ║");
  Serial.println("╚════════════════════════════════════╝");
  
  Serial.println("\n[AYARLAR]");
  Serial.print("  Servo Pin: ");
  Serial.println(SERVO_PIN);
  Serial.print("  Buton Pin: ");
  Serial.println(BUTTON_PIN);
  Serial.print("  Potansiyometre Pin: ");
  Serial.println(POT_PIN);
  Serial.println("\n[KONTROL MODLARI]");
  Serial.println("  1 = Manuel (Seri monitörden)");
  Serial.println("  2 = Otomatik (0-180 arası)");
  Serial.println("  3 = Potansiyometre (Analog)");
  Serial.println("\n[KOMUTLAR]");
  Serial.println("  L = Sola dön");
  Serial.println("  R = Sağa dön");
  Serial.println("  M = Orta konum");
  Serial.println("  O = Otomatik modu");
  Serial.println("  P = Potansiyometre modu");
  Serial.println("  S = Durum görüntüle\n");
  
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buton_interrupt, FALLING);
  
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  
  Serial.println("[HAZIR] Servo kontrol sistemi başadı.\n");
}

void loop() {
  unsigned long simdi = millis();
  
  // Seri komut kontrolü
  if (Serial.available()) {
    char komut = Serial.read();
    isleSeriKomut(komut);
  }
  
  // Mod kontrolü
  switch (modu) {
    case MANUEL:
      // Seri komuttan kontrol (üstte)
      break;
      
    case OTOMATIK:
      otomatikMod();
      break;
      
    case POTANSIYOMETRE:
      potansiyometreMod();
      break;
  }
  
  // Servo pozisyonunu güncelle
  if (simdi - son_okuma >= OKUMA_ARALI) {
    son_okuma = simdi;
    
    // Pozisyonu yavaş yavaş değiştir
    if (pozisyon != hedef_pozisyon) {
      if (pozisyon < hedef_pozisyon) {
        pozisyon++;
      } else {
        pozisyon--;
      }
      
      servo.write(pozisyon);
      digitalWrite(LED_PIN, HIGH);
      delay(10);
      digitalWrite(LED_PIN, LOW);
    }
  }
}

void isleSeriKomut(char komut) {
  komut = toupper(komut);
  
  switch (komut) {
    case 'L':
      Serial.println("[KOMUT] Sola dön (-10 derece)");
      hedef_pozisyon = constrain(hedef_pozisyon - 10, min_pozisyon, max_pozisyon);
      break;
      
    case 'R':
      Serial.println("[KOMUT] Sağa dön (+10 derece)");
      hedef_pozisyon = constrain(hedef_pozisyon + 10, min_pozisyon, max_pozisyon);
      break;
      
    case 'M':
      Serial.println("[KOMUT] Orta konuma git (90 derece)");
      hedef_pozisyon = 90;
      break;
      
    case 'O':
      Serial.println("[MOD] Otomatik moda geçildi!");
      modu = OTOMATIK;
      break;
      
    case 'P':
      Serial.println("[MOD] Potansiyometre moduna geçildi!");
      modu = POTANSIYOMETRE;
      break;
      
    case 'S':
      goster_durum();
      break;
      
    case '0' ... '9':
      // Sayı girdisi - pozisyon ayarla
      String deger_str = String(komut);
      int deger = deger_str.toInt();
      int yeni_pozisyon = map(deger, 0, 9, 0, 180);
      hedef_pozisyon = yeni_pozisyon;
      Serial.print("[POZISYON] Pozisyon ayarlandı: ");
      Serial.println(yeni_pozisyon);
      break;
  }
}

void otomatikMod() {
  hedef_pozisyon += otomatik_yonu * otomatik_hiz;
  
  if (hedef_pozisyon >= max_pozisyon) {
    hedef_pozisyon = max_pozisyon;
    otomatik_yonu = -1;  // Yonu değiştir
    Serial.println("[OTOMATİK] Sınıra ulaşıldı, yön değiştiriliyor.");
  } else if (hedef_pozisyon <= min_pozisyon) {
    hedef_pozisyon = min_pozisyon;
    otomatik_yonu = 1;  // Yonu değiştir
    Serial.println("[OTOMATİK] Sınıra ulaşıldı, yön değiştiriliyor.");
  }
  
  delay(100);
}

void potansiyometreMod() {
  int pot_deger = analogRead(POT_PIN);  // 0-1023
  hedef_pozisyon = map(pot_deger, 0, 1023, 0, 180);  // 0-180'e dönüştür
}

void goster_durum() {
  Serial.println("\n┌─── DURUM ───┐");
  Serial.print("│ Mevcut Pozisyon: ");
  Serial.print(pozisyon);
  Serial.println(" derece");
  Serial.print("│ Hedef Pozisyon: ");
  Serial.print(hedef_pozisyon);
  Serial.println(" derece");
  Serial.print("│ Kontrol Modu: ");
  
  switch (modu) {
    case MANUEL:
      Serial.println("Manuel");
      break;
    case OTOMATIK:
      Serial.println("Otomatik");
      break;
    case POTANSIYOMETRE:
      Serial.println("Potansiyometre");
      break;
  }
  
  Serial.println("└────────────└\n");
}

void buton_interrupt() {
  if (millis() - buton_zamani > DEBOUNCE) {
    buton_basisi++;
    buton_zamani = millis();
    
    Serial.println("[BUTON] Basıldı!");
    
    // Modu değiştir
    modu = (KontrolModu)((modu % 3) + 1);
    Serial.print("[MOD DEĞİŞİM] Yeni Mod: ");
    switch (modu) {
      case MANUEL:
        Serial.println("Manuel");
        break;
      case OTOMATIK:
        Serial.println("Otomatik");
        break;
      case POTANSIYOMETRE:
        Serial.println("Potansiyometre");
        break;
    }
  }
}