# Python Ders 5: Karşılaştırma Operatörleri

a = 10
b = 5

print("=== Karşılaştırma Operatörleri ===")
print()

# Eşittir (==)
print(f"a == b: {a == b}")          # False
print(f"a == 10: {a == 10}")        # True
print(f"'merhaba' == 'merhaba': {'merhaba' == 'merhaba'}")  # True
print()

# Eşit değildir (!=)
print(f"a != b: {a != b}")          # True
print(f"a != 10: {a != 10}")        # False
print()

# Büyüktür (>)
print(f"{a} > {b}: {a > b}")        # True
print(f"{b} > {a}: {b > a}")        # False
print()

# Küçüktür (<)
print(f"{a} < {b}: {a < b}")        # False
print(f"{b} < {a}: {b < a}")        # True
print()

# Büyük veya eşit (>=)
print(f"{a} >= 10: {a >= 10}")      # True
print(f"{a} >= 15: {a >= 15}")      # False
print()

# Küçük veya eşit (<=)
print(f"{b} <= 5: {b <= 5}")        # True
print(f"{a} <= 5: {a <= 5}")        # False
print()

# ===== PRATIK ÖRNEK =====
print("=== Pratik Örnek ===")
yas = 18

if yas >= 18:
    print(f"Yaşınız {yas}, reşitsiniz.")
else:
    print(f"Yaşınız {yas}, henüz reşit değilsiniz.")

# Sınav notu
not = 75

if not >= 90:
    print("Harf: A")
elif not >= 80:
    print("Harf: B")
elif not >= 70:
    print("Harf: C")
else:
    print("Harf: F")