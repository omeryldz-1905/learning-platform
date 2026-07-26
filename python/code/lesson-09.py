# Python Ders 9: For Döngüsü - 500+ Satırlık Detaylı Kod
# Pratik örnekler, projeler ve ileri kullanım

print("="*50)
print("PYTHON FOR DÖNGÜSÜ - KAPSAMLI REHBERİ")
print("="*50)

# ===== BÖLÜM 1: TEMEL FOR DÖNGÜSÜ =====
print("\n[BÖLÜM 1: TEMEL FOR DÖNGÜSÜ]\n")

# Örnek 1.1: Basit sayı döngüsü
print("Örnek 1.1: Basit sayı döngüsü (0-4)")
for i in range(5):
    print(f"  {i}", end=" ")
print("\n")

# Örnek 1.2: Başlangıç ve bitiş
print("Örnek 1.2: Başlangıç (1) ve bitiş (10)")
for i in range(1, 11):
    print(f"  {i}", end=" ")
print("\n")

# Örnek 1.3: Adım belirleme
print("Örnek 1.3: 2'şer atlayarak (0-10)")
for i in range(0, 11, 2):
    print(f"  {i}", end=" ")
print("\n")

# Örnek 1.4: Tersten sayma
print("Örnek 1.4: Tersten sayma (10-1)")
for i in range(10, 0, -1):
    print(f"  {i}", end=" ")
print("\n")

# ===== BÖLÜM 2: LİSTE ÜZERINDE DÖNGÜ =====
print("\n[BÖLÜM 2: LİSTE ÜZERINDE DÖNGÜ]\n")

# Örnek 2.1: Basit liste döngüsü
print("Örnek 2.1: Meyve listesi")
meyveler = ["elma", "armut", "muz", "çilek", "karpuz"]
for meyve in meyveler:
    print(f"  - {meyve}")

# Örnek 2.2: Sayı listesi
print("\nÖrnek 2.2: Sayı listesi işlemleri")
notlar = [85, 90, 78, 92, 88]
toplam = 0
for not_ in notlar:
    toplam += not_
print(f"  Notlar: {notlar}")
print(f"  Toplam: {toplam}")
print(f"  Ortalama: {toplam / len(notlar):.2f}")

# Örnek 2.3: Enumerate ile indeks ve değer
print("\nÖrnek 2.3: Enumerate ile indeks alma")
for indeks, meyve in enumerate(meyveler):
    print(f"  {indeks}: {meyve}")

# Örnek 2.4: Şartlı filtreleme
print("\nÖrnek 2.4: 80'den yukarı notları seç")
basarili_notlar = []
for not_ in notlar:
    if not_ >= 80:
        basarili_notlar.append(not_)
print(f"  80+ Notlar: {basarili_notlar}")

# ===== BÖLÜM 3: STRING ÜZERINDE DÖNGÜ =====
print("\n[BÖLÜM 3: STRING ÜZERINDE DÖNGÜ]\n")

# Örnek 3.1: Kelimeteki harfler
print("Örnek 3.1: Kelimeteki harfler")
kelime = "Python"
for harf in kelime:
    print(f"  {harf}", end=" ")
print("\n")

# Örnek 3.2: Ters string
print("Örnek 3.2: String tersi")
ters_kelime = ""
for harf in kelime:
    ters_kelime = harf + ters_kelime
print(f"  Original: {kelime}")
print(f"  Tersi: {ters_kelime}")

# ===== BÖLÜM 4: BREAK VE CONTINUE =====
print("\n[BÖLÜM 4: BREAK VE CONTINUE]\n")

# Örnek 4.1: break kullanımı
print("Örnek 4.1: Break (5'de dur)")
for i in range(10):
    if i == 5:
        print(f"  {i} bulundu! Döngü durduruluyor.")
        break
    print(f"  {i}", end=" ")
print("\n")

# Örnek 4.2: continue kullanımı
print("Örnek 4.2: Continue (çift sayılar)")
for i in range(1, 11):
    if i % 2 == 1:  # Tek sayıları atla
        continue
    print(f"  {i}", end=" ")
print("\n")

# Örnek 4.3: else kullanımı
print("Örnek 4.3: Else (döngü normal bittiğinde)")
for i in range(5):
    print(f"  {i}", end=" ")
else:
    print("\n  Döngü başarıyla tamamlandı!")

# ===== BÖLÜM 5: İÇ İÇE DÖNGÜLER =====
print("\n[BÖLÜM 5: İÇ İÇE DÖNGÜLER]\n")

# Örnek 5.1: Çarpım tablosu
print("Örnek 5.1: Çarpım Tablosu (3x3)")
for i in range(1, 4):
    for j in range(1, 4):
        print(f"{i*j:2d}", end=" ")
    print()

# Örnek 5.2: Kare deseni
print("\nÖrnek 5.2: 5x5 Kare Deseni")
for i in range(5):
    for j in range(5):
        print("█", end=" ")
    print()

# Örnek 5.3: Üçgen deseni
print("\nÖrnek 5.3: Üçgen Deseni")
for i in range(1, 6):
    for j in range(i):
        print("*", end=" ")
    print()

# Örnek 5.4: Elmas deseni
print("\nÖrnek 5.4: Elmas Deseni")
n = 5
for i in range(1, n + 1):
    boşluk = " " * (n - i)
    yıldız = "*" * (2 * i - 1)
    print(f"{boşluk}{yıldız}")
for i in range(n - 1, 0, -1):
    boşluk = " " * (n - i)
    yıldız = "*" * (2 * i - 1)
    print(f"{boşluk}{yıldız}")

# ===== BÖLÜM 6: PRATIK HESAPLAMALAR =====
print("\n[BÖLÜM 6: PRATIK HESAPLAMALAR]\n")

# Örnek 6.1: Toplam ve Ortalama
print("Örnek 6.1: Toplam ve Ortalama")
notlar = [85, 90, 78, 92, 88, 76, 95, 89]
toplam = 0
for not_ in notlar:
    toplam += not_
ortalama = toplam / len(notlar)
print(f"  Notlar: {notlar}")
print(f"  Toplam: {toplam}")
print(f"  Ortalama: {ortalama:.2f}")

# Örnek 6.2: Faktöriyal
print("\nÖrnek 6.2: Faktöriyal Hesapla")
for n in range(1, 6):
    faktoriyal = 1
    for i in range(1, n + 1):
        faktoriyal *= i
    print(f"  {n}! = {faktoriyal}")

# Örnek 6.3: Fibonacci serileri
print("\nÖrnek 6.3: Fibonacci Serisi (İlk 10)")
a, b = 0, 1
fibbonacci = []
for i in range(10):
    fibbonacci.append(a)
    a, b = b, a + b
print(f"  {fibbonacci}")

# ===== BÖLÜM 7: ASAL SAYILAR =====
print("\n[BÖLÜM 7: ASAL SAYILAR]\n")

print("Örnek 7: Asal sayıları bul (1-30)")
asal_sayilar = []
for sayi in range(2, 31):
    asal_mi = True
    for i in range(2, int(sayi ** 0.5) + 1):
        if sayi % i == 0:
            asal_mi = False
            break
    if asal_mi:
        asal_sayilar.append(sayi)

print(f"  Asal Sayılar: {asal_sayilar}")
print(f"  Toplam: {len(asal_sayilar)} asal sayı")

# ===== BÖLÜM 8: SÖZLÜK DÖNGÜSÜ =====
print("\n[BÖLÜM 8: SÖZLÜK DÖNGÜSÜ]\n")

ogrenci = {"ad": "Ahmet", "yaş": 20, "sınıf": "10-B"}
print("Örnek 8: Sözlük döngüsü")
for anahtar, değer in ogrenci.items():
    print(f"  {anahtar}: {değer}")

print("\n" + "="*50)
print("TAMAMLANDI!")
print("="*50)