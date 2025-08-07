#slide 20
import random

while True:
    try:
        inicio = int(input("\nDigite um número: "))
        fim = int(input("Digite outro número: "))
        quantidade = int(input("Digite a quantidade de números a serem, sorteados: "))
        if quantidade > (fim - inicio + 1): 
            continue
        break
    except:
        continue
lista = []
while len(lista) < quantidade:
    x = random.randint(inicio, fim)
    if x not in lista:
        lista.append(x)
    else:
        continue
print(lista)