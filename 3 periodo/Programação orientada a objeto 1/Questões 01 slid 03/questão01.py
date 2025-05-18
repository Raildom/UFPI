#slide 19
lista = []
par = []
impar = []

while True:
    while True:    
        try:
            num = int(input("Digite o numero inicial: "))
            break
        except:
            continue
    if num < 0:
        break
    elif num == 0:
        lista.append(num)
    elif num % 2 == 0:
        par.append(num)
    elif num % 2 != 0:
        impar.append(num)
par.sort()
impar.sort()
par.extend(lista)
par.extend(impar)
print(par)
