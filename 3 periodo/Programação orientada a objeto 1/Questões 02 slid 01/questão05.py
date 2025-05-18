num1 = int(input("Digite o primeiro número: "))
num2 = int(input("Digite o segundo número: "))

resultado = 1
for i in range(num2):
    resultado *= num1
print(f":{resultado}")