lista = [0,0,0,0,0,0,0,0,0,0]
fim = 9
for i in range(0, 10):
    lista[i] = input("Digite um elemento: ")
print(lista)
for i in range(0, 10 // 2):
    aux = lista[i]
    lista[i] = lista[fim]
    lista[fim] = aux
    fim -= 1
print(lista)