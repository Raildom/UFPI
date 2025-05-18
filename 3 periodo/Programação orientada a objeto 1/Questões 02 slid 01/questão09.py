fibonacci = int(input("Digite o número do FIBONACCI: "))
a, b = 0, 1

for i in range(fibonacci + 1):
    print(a, end=' ')
    a, b = b, a + b