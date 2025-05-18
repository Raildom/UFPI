agenda = {}

def incluirNovoNome(agenda, nome, telefones):
    if nome in agenda:
        return False
    agenda[nome] = telefones

def incluirTelefone(agenda, nome, telefone):
    if nome in agenda:
        agenda[nome].append(telefone)
    else:
        resposta = input(f"O nome {nome} não está na agenda. Deseja incluí-lo? (s/n): ")
        if resposta.lower() == 's':
            telefones = [telefone]
            incluirNovoNome(agenda, nome, telefones)

def excluirTelefone(agenda, nome, telefone):
    if nome in agenda:
        if telefone in agenda[nome]:
            agenda[nome].remove(telefone)
            if not agenda[nome]:
                del agenda[nome]
        else:
            print(f"O telefone {telefone} não está associado ao nome {nome}.")
    else:
        print(f"O nome {nome} não está na agenda.")

def excluirNome(agenda, nome):
    if nome in agenda:
        del agenda[nome]
    else:
        print(f"O nome {nome} não está na agenda.")

def consultarTelefone(agenda, nome):
    if nome in agenda:
        return agenda[nome]
    else:
        print(f"O nome {nome} não está na agenda.")
        return []

while True:
    print("\n[1]. Incluir novo nome")
    print("[2]. Incluir telefone")
    print("[3]. Excluir telefone")
    print("[4]. Excluir nome")
    print("[5]. Consultar telefone")
    print("Digite um numero negativo para sair.")
    opcao = int(input("Escolha uma opção: "))
    
    if opcao == 1:
        nome = input("Digite o nome: ")
        telefones = input("Digite os telefones separados por espaço: ").split()
        incluirNovoNome(agenda, nome, telefones)
    elif opcao == 2:
        nome = input("Digite o nome: ")
        telefone = input("Digite o telefone: ")
        incluirTelefone(agenda, nome, telefone)
    elif opcao == 3:
        nome = input("Digite o nome: ")
        telefone = input("Digite o telefone: ")
        excluirTelefone(agenda, nome, telefone)
    elif opcao == 4:
        nome = input("Digite o nome: ")
        excluirNome(agenda, nome)
    elif opcao == 5:
        nome = input("Digite o nome: ")
        telefones = consultarTelefone(agenda, nome)
        if telefones:
            print(f"Telefones de {nome}: {', '.join(telefones)}")
    elif opcao < 0:
        break
    else:
        print("Opção inválida. Tente novamente.")
