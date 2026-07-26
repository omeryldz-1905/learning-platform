# Python Ders 6: Mantıksal Operatörler

print("=== AND (ve) ===")
print(True and True)      # True
print(True and False)     # False
print(False and False)    # False
print()

print("=== OR (veya) ===")
print(True or False)      # True
print(True or True)       # True
print(False or False)     # False
print()

print("=== NOT (değil) ===")
print(not True)           # False
print(not False)          # True
print()

print("=== Pratik Örnekler ===")

# AND örneği
yas = 25
uzunluk = 180

if yas >= 18 and uzunluk >= 160:
    print(f"Yaş: {yas}, Boy: {uzunluk}")
    print("✓ Roller coaster'a binebilirsin!")
else:
    print("✗ Maalesef binemezsin.")
print()

# OR örneği
hava = "yağmurlu"
ev_var = True

if hava == "yağmurlu" or ev_var:
    print("Şemsiye al veya evde kal!")
print()

# NOT örneği
loggedIn = False

if not loggedIn:
    print("Lütfen giriş yap!")
else:
    print("Hoş geldiniz!")
print()

# Karmaşık örnek
yas = 20
pazarlama = True
fizik_engel = False

if (yas >= 18) and (pazarlama or not fizik_engel):
    print("✓ İşe alındınız!")
else:
    print("✗ Başvurunuz reddedildi.")