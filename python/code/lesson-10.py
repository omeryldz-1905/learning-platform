# Python Ders 10: While Döngüsü - 600+ Satırlık Detaylı Kod

print("="*60)
print("PYTHON WHILE DÖNGÜSÜ - KAPSAMLI REHBERİ")
print("="*60)

# ===== BÖLÜM 1: TEMEL WHILE DÖNGÜSÜ =====
print("\n[BÖLÜM 1: TEMEL WHILE DÖNGÜSÜ]\n")

# Örnek 1.1: Basit sayı döngüsü
print("Örnek 1.1: While ile sayı yazdırma (0-4)")
i = 0
while i < 5:
    print(f"  {i}", end=" ")
    i += 1
print("\n")

# Örnek 1.2: Koşullu döngü
print("Örnek 1.2: Kullanıcıdan giriş alıp sayı taraflı")
kullanici_input = input("  Bir sayı girin (veya 'q' yazarak çıkın): ")
if kullanici_input.lower() != 'q':
    try:
        sayi = int(kullanici_input)
        print(f"  Girdiğiniz sayı: {sayi}")
    except ValueError:
        print("  Geçersiz giriş!")

# Örnek 1.3: Tersten sayma
print("\nÖrnek 1.3: Tersten sayma (5-0)")
i = 5
while i >= 0:
    print(f"  {i}", end=" ")
    i -= 1
print("\n")

# Örnek 1.4: Çift sayılar
print("Örnek 1.4: Çift sayılar (1-10)")
i = 2
while i <= 10:
    print(f"  {i}", end=" ")
    i += 2
print("\n")

# ===== BÖLÜM 2: BREAK VE CONTINUE =====
print("\n[BÖLÜM 2: BREAK VE CONTINUE]\n")

# Örnek 2.1: Break kullanımı
print("Örnek 2.1: Break (5'te dur)")
i = 0
while True:
    if i == 5:
        print(f"  {i} bulundu! Döngü durduruluyor.")
        break
    print(f"  {i}", end=" ")
    i += 1
print("\n")

# Örnek 2.2: Continue kullanımı
print("Örnek 2.2: Continue (3 ve 7 atla)")
i = 0
while i < 10:
    if i == 3 or i == 7:
        i += 1
        continue
    print(f"  {i}", end=" ")
    i += 1
print("\n")

# ===== BÖLÜM 3: WHILE-ELSE =====
print("\n[BÖLÜM 3: WHILE-ELSE]\n")

# Örnek 3.1: Else (break olmadan)
print("Örnek 3.1: Else (normal bitiş)")
i = 0
while i < 3:
    print(f"  {i}", end=" ")
    i += 1
else:
    print("\n  Döngü normal bitti!")

# Örnek 3.2: Else (break ile)
print("\nÖrnek 3.2: Else (break çağırsa çalışmaz)")
i = 0
while i < 10:
    if i == 3:
        print(f"  {i} bulundu! Break çağrılıyor.")
        break
    print(f"  {i}", end=" ")
    i += 1
else:
    print("  Bu yazılmayacak!")
print()

# ===== BÖLÜM 4: PRATIK UYGULAMALAR =====
print("\n[BÖLÜM 4: PRATIK UYGULAMALAR]\n")

# Örnek 4.1: Kullanıcı doğrulaması
print("Örnek 4.1: Doğru sayı bulana kadar")
simulasyon_sayi = 7
tahmin = -1
tahmin_sayisi = 0

while tahmin != simulasyon_sayi:
    try:
        tahmin = int(input("  Bir sayı tahmin et (1-10): "))
        tahmin_sayisi += 1
        
        if tahmin < simulasyon_sayi:
            print("    Daha büyük bir sayı deneyin!")
        elif tahmin > simulasyon_sayi:
            print("    Daha küçük bir sayı deneyin!")
        else:
            print(f"    Doğru! {tahmin_sayisi} tahminde buldunuz!")
    except ValueError:
        print("    Lütfen bir sayı girin!")

# Örnek 4.2: Toplam hesapla
print("\nÖrnek 4.2: Sayıların toplamı (negatif sayıya kadar)")
toplam = 0
sayi = 0
sayac = 0

while True:
    try:
        sayi = int(input("  Bir sayı girin (ışıktan çıkmak için -1 yazabilirsiniz): "))
        if sayi == -1:
            break
        toplam += sayi
        sayac += 1
    except ValueError:
        print("    Lütfen geçerli bir sayı girin!")

if sayac > 0:
    print(f"  Toplam: {toplam}")
    print(f"  Ortalama: {toplam / sayac:.2f}")
    print(f"  Sayı adedi: {sayac}")

# Örnek 4.3: Doğulama döngüsü
print("\nÖrnek 4.3: E-posta doğrulaması")
while True:
    email = input("  E-posta adresi girin: ")
    if "@" in email and "." in email:
        print(f"  ✓ Geçerli e-posta: {email}")
        break
    else:
        print("  ✗ Geçersiz e-posta! Lütfen tekrar deneyin.")

# Örnek 4.4: Sayaç ile kontrol
print("\nÖrnek 4.4: İki saniye geri sayış")
import time
saniye = 3
while saniye > 0:
    print(f"  {saniye}...", end="", flush=True)
    time.sleep(0.5)
    saniye -= 1
print("\n  Başladı!\n")

# ===== BÖLÜM 5: İÇ İÇE WHILE DÖNGÜLERİ =====
print("[BÖLÜM 5: İÇ İÇE WHILE DÖNGÜLERİ]\n")

# Örnek 5.1: Çarpım tablosu
print("Örnek 5.1: Çarpım Tablosu (While ile)")
i = 1
while i <= 3:
    j = 1
    while j <= 3:
        print(f"{i*j:2d}", end=" ")
        j += 1
    print()
    i += 1

# Örnek 5.2: Desen
print("\nÖrnek 5.2: Piramit Deseni")
i = 1
while i <= 5:
    j = 1
    while j <= i:
        print("*", end=" ")
        j += 1
    print()
    i += 1

# ===== BÖLÜM 6: ORTAK HATA’LER =====
print("\n[BÖLÜM 6: ORTAK HATALAR VE ÇÖZÜMLER]\n")

print("⚠️  HATA 1: Sonsuz döngü")
print("  Yanlış: while True: print('a')  # Çıkış yok!")
print("  Doğru: while True:")
print("      print('a')")
print("      if <koşul>: break\n")

print("⚠️  HATA 2: Değişken güncellemesi unut")
print("  Yanlış: while i < 5: print(i)  # i değişmiyor")
print("  Doğru: while i < 5:")
print("      print(i)")
print("      i += 1\n")

print("="*60)
print("TAMAMLANDI!")
print("="*60)