tabuada = int(input("Montar a tabuada do: "))
inicio = int(input("Começar por: "))
fim = int(input("Termina em: "))

for i in range(inicio, fim + 1):
    print(f"{tabuada} X {i} = {tabuada * i}")