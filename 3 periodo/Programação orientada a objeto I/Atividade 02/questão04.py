string = input("Digite uma string qualquer: ")

def tamString(s):
    count = 0
    for i in s:
        count += 1
    return count

def compara(string):
    lista = list(string)
    for i in range(0, tamString(string)):
        for j in range(i, tamString(string)):    
            if lista[j] < lista[i]:
                aux = lista[j]
                lista[j] = lista[i]
                lista[i] = aux
    novaString = ''.join(lista)
    return novaString
            
print(compara(string))