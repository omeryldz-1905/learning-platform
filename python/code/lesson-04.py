# Python Ders 4: Matematiksel Operatörler

# ===== TOPLAMA =====
num1 = 10
num2 = 5
toplam = num1 + num2
print(f"Toplama: {num1} + {num2} = {toplam}")
print()

# ===== ÇIKARMA =====
fark = num1 - num2
print(f"Çıkarma: {num1} - {num2} = {fark}")
print()

# ===== ÇARPMA =====
çarpim = num1 * num2
print(f"Çarpma: {num1} * {num2} = {çarpim}")
print()

# ===== BÖLME =====
bolum = num1 / num2
print(f"Bölme: {num1} / {num2} = {bolum}")
print()

# ===== TAM BÖLME =====
tam_bolum = num1 // num2
print(f"Tam Bölme: {num1} // {num2} = {tam_bolum}")
print()

# ===== MOD (KALAN) =====
kalan = num1 % num2
print(f"Mod: {num1} % {num2} = {kalan}")
print()

# ===== ÜS ALMA =====
kare = 5 ** 2
kup = 5 ** 3
print(f"Üs: 5 ** 2 = {kare}")
print(f"Üs: 5 ** 3 = {kup}")
print()

# ===== İŞLEM SIRASI =====
sonuc = 2 + 3 * 4
print(f"İşlem Sırası: 2 + 3 * 4 = {sonuc} (çarpma önce yapılır)")

sonuc2 = (2 + 3) * 4
print(f"Parantezli: (2 + 3) * 4 = {sonuc2}")
print()

# ===== PRATIK ÖRNEK =====
print("=== Fatura Hesaplama ===")
ayakkabi_fiyati = 99.99
iskonto = 0.15  # %15
vergi = 0.18    # %18

iskonto_tutari = ayakkabi_fiyati * iskonto
fiyat_iskonto_sonrasi = ayakkabi_fiyati - iskonto_tutari
vergi_tutari = fiyat_iskonto_sonrasi * vergi
toplam_fiyat = fiyat_iskonto_sonrasi + vergi_tutari

print(f"Orijinal Fiyat: {ayakkabi_fiyati} ₺")
print(f"İskonto (%15): {iskonto_tutari:.2f} ₺")
print(f"İskonto Sonrası: {fiyat_iskonto_sonrasi:.2f} ₺")
print(f"Vergi (%18): {vergi_tutari:.2f} ₺")
print(f"Toplam Fiyat: {toplam_fiyat:.2f} ₺")