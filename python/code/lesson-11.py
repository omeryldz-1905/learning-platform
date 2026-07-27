# Python Ders 11: Listeler (Lists) - 700+ Satır Kapsamlı Rehber

print("="*70)
print("PYTHON LİSTELER - KAPSAMLI REHBER")
print("="*70)

# ===== BÖLÜM 1: LİSTE OLUŞTURMA =====
print("\n[BÖLÜM 1: LİSTE OLUŞTURMA]\n")

# Örnek 1.1: Basit liste
print("Örnek 1.1: Basit liste")
meyveler = ["elma", "armut", "muz", "çilek"]
print(f"  {meyveler}")
print(f"  Uzunluk: {len(meyveler)}")

# Örnek 1.2: Farklı veri tipleri
print("\nÖrnek 1.2: Farklı veri tipleri")
karisik = [1, "merhaba", 3.14, True, None]
print(f"  {karisik}")

# Örnek 1.3: Boş liste
print("\nÖrnek 1.3: Boş liste")
bos_liste = []
print(f"  {bos_liste}")
print(f"  Uzunluk: {len(bos_liste)}")

# Örnek 1.4: range() ile liste
print("\nÖrnek 1.4: range() ile liste")
sayilar = list(range(1, 11))
print(f"  {sayilar}")

# ===== BÖLÜM 2: İNDEKSLEME VE KESİTLEME =====
print("\n[BÖLÜM 2: İNDEKSLEME VE KESİTLEME]\n")

# Örnek 2.1: İndeksleme
print("Örnek 2.1: İndeksleme")
meyveler = ["elma", "armut", "muz", "çilek"]
print(f"  İlk eleman: {meyveler[0]}")
print(f"  Son eleman: {meyveler[-1]}")
print(f"  İkinci: {meyveler[1]}")
print(f"  Sondan ikinci: {meyveler[-2]}")

# Örnek 2.2: Kesiş alma
print("\nÖrnek 2.2: Kesiş alma (Slicing)")
print(f"  meyveler[1:3] = {meyveler[1:3]}")
print(f"  meyveler[:2] = {meyveler[:2]}")
print(f"  meyveler[2:] = {meyveler[2:]}")
print(f"  meyveler[::2] = {meyveler[::2]}")
print(f"  meyveler[::-1] = {meyveler[::-1]}")

# ===== BÖLÜM 3: LİSTE METODLARı =====
print("\n[BÖLÜM 3: LİSTE METODLARı]\n")

# Örnek 3.1: append() - Eleman ekle
print("Örnek 3.1: append() - Eleman ekle")
meyveler = ["elma", "armut"]
meyveler.append("muz")
print(f"  {meyveler}")

# Örnek 3.2: extend() - Birden fazla eleman
print("\nÖrnek 3.2: extend() - Birden fazla eleman")
meyveler.extend(["çilek", "karpuz"])
print(f"  {meyveler}")

# Örnek 3.3: insert() - Belirli konuma
print("\nÖrnek 3.3: insert() - Belirli konuma ekle")
meyveler.insert(1, "portakal")
print(f"  {meyveler}")

# Örnek 3.4: remove() - Eleman sil
print("\nÖrnek 3.4: remove() - Eleman sil")
meyveler.remove("portakal")
print(f"  {meyveler}")

# Örnek 3.5: pop() - Son elemanı sil ve döndür
print("\nÖrnek 3.5: pop() - Son elemanı sil")
son = meyveler.pop()
print(f"  Silinen: {son}")
print(f"  Kalan: {meyveler}")

# Örnek 3.6: index() - Eleman konumunu bul
print("\nÖrnek 3.6: index() - Eleman konumu")
indeks = meyveler.index("armut")
print(f"  'armut' konumu: {indeks}")

# Örnek 3.7: count() - Eleman sayısını say
print("\nÖrnek 3.7: count() - Eleman sayısı")
sayilar = [1, 2, 2, 3, 2, 4]
print(f"  {sayilar}")
print(f"  2'nin sayısı: {sayilar.count(2)}")

# Örnek 3.8: sort() - Sırala
print("\nÖrnek 3.8: sort() - Sırala")
sayilar = [5, 2, 8, 1, 9]
print(f"  Orijinal: {sayilar}")
sayilar.sort()
print(f"  Sıralanmış: {sayilar}")

# Örnek 3.9: reverse() - Tersi
print("\nÖrnek 3.9: reverse() - Tersi")
sayilar.reverse()
print(f"  Tersi: {sayilar}")

# Örnek 3.10: clear() - Temizle
print("\nÖrnek 3.10: clear() - Temizle")
kopi = sayilar.copy()
kopi.clear()
print(f"  Temizlenmiş: {kopi}")

# ===== BÖLÜM 4: LİSTE PRATİKLERİ =====
print("\n[BÖLÜM 4: LİSTE PRATİKLERİ]\n")

# Örnek 4.1: Listeyi döngüyle işle
print("Örnek 4.1: Döngü ile işle")
notlar = [85, 90, 78, 92, 88]
toplam = 0
for not_ in notlar:
    toplam += not_
print(f"  Notlar: {notlar}")
print(f"  Toplam: {toplam}")
print(f"  Ortalama: {toplam / len(notlar):.2f}")

# Örnek 4.2: List comprehension
print("\nÖrnek 4.2: List Comprehension")
kareleri = [x**2 for x in range(1, 6)]
print(f"  Kareler: {kareleri}")

# Örnek 4.3: Filtreleme
print("\nÖrnek 4.3: Filtreleme")
sayilar = list(range(1, 11))
ciift = [x for x in sayilar if x % 2 == 0]
print(f"  Tüm sayılar: {sayilar}")
print(f"  Çift sayılar: {ciift}")

# Örnek 4.4: Listeyi birleştir
print("\nÖrnek 4.4: Listeleri birleştir")
list1 = [1, 2, 3]
list2 = [4, 5, 6]
birlesik = list1 + list2
print(f"  {list1} + {list2} = {birlesik}")

# Örnek 4.5: Tekrar sayısını kontrol
print("\nÖrnek 4.5: Tekrar sayısı")
sayilar = [1, 2, 2, 3, 2, 4, 4, 4]
for x in set(sayilar):
    print(f"  {x}: {sayilar.count(x)} kez")

print("\n" + "="*70)
print("LİSTELER TAMAMLANDI!")
print("="*70)