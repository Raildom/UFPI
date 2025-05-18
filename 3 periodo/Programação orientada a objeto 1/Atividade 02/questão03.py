string = input("Digite uma palavra: ")
caractere = input("Digite o caractere a ser encontrado: ")

def busca(string, caractere):
    count = 0
    for i in string:
        if i == caractere:
            return count
        count += 1
            
print(busca(string, caractere))