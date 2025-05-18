dicionario = {}

def media(nota1, nota2):
    return (nota1 + nota2) / 2

while True:
    lista = []
    nome = input("\nDigite o nome do aluno ou sair para finalizar: ")
    if nome.lower() == "sair":
        break
    nota1 = float(input("Digite a primera nota: "))
    lista.append(nota1)
    nota2 = float(input("Digite a nota do aluno: "))
    lista.append(nota2)
    dicionario[nome] = lista

while True:
    escolha = input("\nDigite o nome do aluno para ver a média ou sair para finalizar: ")
    if escolha.lower() == "sair":
        break
    if escolha not in dicionario:
        print("Aluno não encontrado")
        continue
    print(f"A média do aluno {escolha} é {media(dicionario[escolha][0], dicionario[escolha][1])}")