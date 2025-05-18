def fatorial(n):
    if n < 2:
        return 1
    else:    
        i = n - 1
        while i > 1:
            n *= i
            i -= 1
        return n

def combinacao(n, k):
    return fatorial(n) / (fatorial(k) * fatorial(n - k))

def arranjo(n, k):
    return fatorial(n) / fatorial(n - k)

while True:
    try:
        n = int(input("Digite o n: "))
        k = int(input("Digite o k: "))
        break
    except:
        continue
print(f"Combinação de {n} e {k}: {combinacao(n, k)}")
print(f"Arranjo de {n} e {k}: {arranjo(n, k)}")