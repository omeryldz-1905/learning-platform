# Python Ders 8: String Metodları

print("=== String Metodları ===")
print()

metin = "Merhaba Dünya!"
print(f"Original: {metin}")
print()

# upper() - Büyük harfe çevir
print(f"upper(): {metin.upper()}")

# lower() - Küçük harfe çevir
print(f"lower(): {metin.lower()}")

# capitalize() - İlk harfi büyük yap
print(f"capitalize(): {metin.capitalize()}")

# title() - Her kelimenin ilk harfini büyük yap
print(f"title(): {metin.title()}")
print()

# len() - Uzunluk
print(f"len(): {len(metin)} karakter")

# replace() - Değiştir
print(f"replace('Dünya', 'Python'): {metin.replace('Dünya', 'Python')}")
print()

# split() - Böl (liste oluştur)
sozler = metin.split()
print(f"split(): {sozler}")

# join() - Birleştir
sonuc = "-".join(sozler)
print(f"join('-'): {sonuc}")
print()

# strip() - Başındaki ve sonundaki boşluk kaldır
metin2 = "  Merhaba  "
print(f"strip(): '{metin2.strip()}'")

# lstrip() - Soldan boşluk kaldır
print(f"lstrip(): '{metin2.lstrip()}'")

# rstrip() - Sağdan boşluk kaldır
print(f"rstrip(): '{metin2.rstrip()}'")
print()

# find() - Bul (indeks döndür)
indeks = metin.find("Dünya")
print(f"find('Dünya'): {indeks}")

# count() - Sayı
print(f"count('a'): {metin.count('a')}")

# startswith() / endswith()
print(f"startswith('Merhaba'): {metin.startswith('Merhaba')}")
print(f"endswith('!'): {metin.endswith('!')}")
print()

# isdigit() / isalpha() / isalnum()
print(f"'123'.isdigit(): {'123'.isdigit()}")
print(f"'abc'.isalpha(): {'abc'.isalpha()}")
print(f"'abc123'.isalnum(): {'abc123'.isalnum()}")
print()

# ===== PRATIK ÖRNEK =====
print("=== Pratik Örnek: Adı Biçimlendir ===")
ad = "  ahmet yilmaz  "
print(f"Original: '{ad}'")

# Temizle ve Biçimlendir
temiz_ad = ad.strip().title()
print(f"Temizlenmiş: '{temiz_ad}'")