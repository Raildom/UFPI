contador = 0
while contador <= 40:
    if contador == 40:
        print("FIM")
    elif contador % 4 == 0:
        print("PIN")
    else:
        print(contador)
    contador += 1