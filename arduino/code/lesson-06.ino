// Buzzer ile Ses Çıkartma - Ders 6

int buzzerPin = 8;

// Müzik notalarının frekansları (Hz)
int DO = 262;      // C4
int RE = 294;      // D4
int MI = 330;      // E4
int FA = 349;      // F4
int SOL = 392;     // G4
int LA = 440;      // A4
int SI = 494;      // B4
int DO_HIGH = 523; // C5

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Skala çal
  playNote(DO, 300);
  playNote(RE, 300);
  playNote(MI, 300);
  playNote(FA, 300);
  playNote(SOL, 300);
  playNote(LA, 300);
  playNote(SI, 300);
  playNote(DO_HIGH, 300);
  
  delay(1000);
}

void playNote(int frequency, int duration) {
  tone(buzzerPin, frequency, duration);
  delay(duration + 50);
}