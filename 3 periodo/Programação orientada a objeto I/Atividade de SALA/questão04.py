def valor_serie(n):
    s = 0
    for i in range(1, n + 1):
        s += i / (i *  2 - 1)
    return s

n = int(input("Digite o valor de n: "))
print(f"O valor da série é: {valor_serie(n)}")