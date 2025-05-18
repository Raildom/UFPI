import random
lista = []
cartao1 = [1, []]
cartao2 = [2, []]
cartao3 = [3, []]
count1 = 0
count2 = 0
count3 = 0

def gerarNumero():
    return random.randint(1, 3)

for i in range(0, 13):
    lista.append(gerarNumero())
    cartao1[1].append(gerarNumero())
    cartao2[1].append(gerarNumero())
    cartao3[1].append(gerarNumero())
    
for i in range(0, 13):
    if lista[i] == cartao1[1][i]:
        count1 += 1
    if count1 == 13:
        print(f"Ganhador: {cartao1[0]}")
    if lista[i] == cartao2[1][i]:
        count2 += 1
    if count2 == 13:
        print(f"Ganhador: {cartao2[0]}")
    if lista[i] == cartao3[1][i]:
        count3 += 1
    if count3 == 13:
        print(f"Ganhador: {cartao3[0]}")
print(f"cartão {cartao1[0]}. Numero de acertos: {count1}")
print(f"cartão {cartao2[0]}. Numero de acertos: {count2}")
print(f"cartão {cartao3[0]}. Numero de acertos: {count3}")