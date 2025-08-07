while True:
    try:
        num = int(input("Digite um número: "))
        break
    except:
        continue
binario = ""

while num > 1:
    resto = num % 2
    binario = str(resto) + binario
    num //= 2
binario = str(1) + binario
    
print(f"BINÁRIO: {binario}")