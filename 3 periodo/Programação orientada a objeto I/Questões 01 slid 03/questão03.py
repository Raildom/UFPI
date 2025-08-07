lista=[12,-2,4,8,29,45,78,36,-17,2,12,8,3,3,-52]
cont = 0
maior = 0
menor = lista[0]
pares = []
soma = 0
media = 0
somaN = 0

for i in lista:
    if i > maior:
        maior = i
    if i < menor:
        menor = i
    if i % 2 == 0:
        pares.append(i)
    if lista[0] == i:  
        cont += 1
    if i < 0:
        somaN += i
    soma += i
print(f"MAIOR = {maior}\nMENOR: {menor}\nPARES: {pares}\nOCORRÊNCIAS: {cont}\nMÉDIA: {soma / 15}\nSOMA DOS NEGATIVOS: {somaN}")