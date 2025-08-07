produtos = {}

def adicionar_novo_produto(produtos, nome, preco, categoria):
    if nome in produtos:
        return False, "Produto já cadastrado"
    else:
        produtos[nome] = [preco, categoria]
        return True, "Item adicionado com sucesso!\n"
        
def listar_todos_cadastrados(produtos):
    return produtos.items()
    
def busca(produtos, busca_nome):
    if busca_nome not in produtos:
        return False, "Produto não encontrado"
    else:
        return busca_nome, produtos[busca_nome]
    
def remove(produtos, remover):        
    if remover in produtos.keys():
        del produtos[remover]
        return True, "Item removido com sucesso!\n"
    else:
        return False, "Produto não encontrado!\n"
    
def menu():
    while True:
        op = int(input("\n[1] Adicionar novo produto\n[2] listar todos\n[3] Buscar por nome\n[4] Remover por nome\n[5] sair\n: "))
        
        if op == 5:
            break
        elif op == 1:
            nome = input("Digite o nome: ")
            preco = float(input("Digite o preço: "))
            categoria = input("Digite a categoria: ")
            retorno = adicionar_novo_produto(produtos, nome, preco, categoria)
            if retorno[0] == False:
                print(retorno[1])
        elif op == 2:
            resultado = listar_todos_cadastrados(produtos)
            for i in resultado:
                print(i)
        elif op == 3:
            busca_nome = input("Digite o nome do produto que será buscado: ")
            resultado = busca(produtos, busca_nome)
            if resultado[0] == True:
                print(resultado[1])
            else:
                print(resultado)
        elif op == 4:
            remover = input("Digite o nome do produto que deseja remover: ")
            remove(produtos, remover)           
menu()