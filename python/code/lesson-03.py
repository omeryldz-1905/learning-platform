# Python Ders 3: Giriş Alma

# ===== TEMEL İNPUT =====
adı = input("Adını gir: ")
print(f"Merhaba {adı}!")
print()

# ===== SAYI GİRİŞİ =====
# Not: input() her zaman string döndürür!
# İnteger'a dönüştürmek için int() kullan

yaş = int(input("Yaşını gir: "))
print(f"Yaşın: {yaş}")
print(f"10 sene sonra yaşın: {yaş + 10}")
print()

# ===== ONDALIK SAYI =====
kilo = float(input("Kilonu gir: "))
print(f"Kilonuz: {kilo} kg")
print()

# ===== MATEMATİK İŞLEMİ =====
num1 = float(input("1. sayıyı gir: "))
num2 = float(input("2. sayıyı gir: "))

toplam = num1 + num2
fark = num1 - num2
çarpım = num1 * num2
bölüm = num1 / num2

print(f"{num1} + {num2} = {toplam}")
print(f"{num1} - {num2} = {fark}")
print(f"{num1} * {num2} = {çarpım}")
print(f"{num1} / {num2} = {bölüm}")