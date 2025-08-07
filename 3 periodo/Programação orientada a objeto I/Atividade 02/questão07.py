lista1 = []
lista2 = []
lista3 = []

print("Primeira lista: ")
for i in range(0, 10):
    x = float(input(f"Digite o {i + 1} numero: "))
    lista1.append(x)
print("Segunda lista: ")
for i in range(0, 10):
    x = float(input(f"Digite o {i + 1} numero: "))
    lista2.append(x)
for i in range(0, 10):
    resultado = lista1[i] * lista2[i]
    lista3.append(resultado)
print(lista3)