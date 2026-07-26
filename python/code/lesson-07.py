# Python Ders 7: If/Elif/Else

print("=== Basit If ===")
yas = 20

if yas >= 18:
    print(f"Yaşınız {yas}, reşitsiniz!")
print()

print("=== If/Else ===")
gun = "Pazar"

if gun == "Pazar":
    print("Haftasonuna hoş geldiniz!")
else:
    print("Bugün çalışma günü.")
print()

print("=== If/Elif/Else ===")
not = int(input("Sınav notunuzu girin (0-100): ") or "75")

if not >= 90:
    print(f"Not: {not}")
    print("Harf: A - Çok İyi")
elif not >= 80:
    print(f"Not: {not}")
    print("Harf: B - İyi")
elif not >= 70:
    print(f"Not: {not}")
    print("Harf: C - Yeterli")
elif not >= 60:
    print(f"Not: {not}")
    print("Harf: D - Zayıf")
else:
    print(f"Not: {not}")
    print("Harf: F - Başarısız")
print()

print("=== İç İçe If ===")
hava = "güneşli"
temperatur = 25

if hava == "güneşli":
    print(f"Hava: {hava}")
    if temperatur > 20:
        print(f"Sıcaklık: {temperatur}°C")
        print("✓ Dışarıya çık ve oyna!")
    else:
        print(f"Sıcaklık: {temperatur}°C")
        print("✓ Dışarıya çık ama ceket giy!")
elif hava == "yağmurlu":
    print("✗ Evde kal! Yağmur yağıyor.")
else:
    print("✗ Evde kal!")
print()

print("=== Ternary İfade ===")
yas = 20
mesaj = "Reşit" if yas >= 18 else "Reşit değil"
print(f"Yaş: {yas} -> {mesaj}")