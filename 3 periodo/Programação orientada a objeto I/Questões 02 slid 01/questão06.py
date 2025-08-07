num = int(input("Digite um número: "))
fatorial = 1

while(num != 0):
    fatorial *= num
    num -= 1
print(f"Fatorial: {fatorial}")