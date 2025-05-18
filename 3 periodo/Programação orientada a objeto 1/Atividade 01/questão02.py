def fatorial_iterativo(num):
    if num < 2:
        return 1
    else:    
        i = num - 1
        while i > 1:
            num *= i
            i -= 1
        return num

def fatorial_recursivo(num):
    if num < 2:
        return 1
    else:
        return num * fatorial_recursivo(num - 1)
    
while True:
    try:
        num = int(input("Digite um número inteiro e positivo: "))
        break
    except:
        continue
    
resposta = fatorial_iterativo(num)
print(f"FATORIAL ITERATIVO: {resposta}")
resposta = fatorial_recursivo(num)
print(f"FATORIAL RECURSIVO: {resposta}")