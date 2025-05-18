import random
lista = [0, 0, 0, 0, 0, 0]

for i in range(0, 100):
    x = random.randint(1, 6 )
    if x == 1:
        lista[0] += 1
    elif x == 2:
        lista[1] += 1
    elif x == 3:
        lista[2] += 1
    elif x == 4:
        lista[3] += 1
    elif x == 5:
        lista[4] += 1
    elif x == 6:
        lista[5] += 1
print(lista)