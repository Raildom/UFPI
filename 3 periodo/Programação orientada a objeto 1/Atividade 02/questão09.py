linhas = 10
colunas = 5
matriz = []

for i in range(linhas):
    linha = []
    nome = input(f"Digite o nome da pessoa {i + 1}: ")
    endereco = input("Digite o endereço: ")
    cep = input("Digite o CEP: ")
    bairro = input("Digite o bairro: ")
    telefone = input("Digite o telefone: ")
    linha.extend([nome, endereco, cep, bairro, telefone])
    matriz.append(linha)

print("\nDados:")
for linha in matriz:
    print(linha)