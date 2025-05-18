class Pessoa:
    def __init__(self, nome, idade):
        self._nome = nome
        self._idade = idade
        
    @property
    def nome(self):
        return self._nome
    
    @nome.setter
    def nome(self, nome):
        self._nome = nome
        
    @property
    def idade(self):
        return self._idade
    
    @idade.setter
    def idade(self, idade):
        print("Idade não pode ser alterada")

class Agenda:
    def __init__(self):
        self.pessoas = {}
        self.quantidade = 0
    
    def armazenar_pessoa(self, nome, idade):
        if len(self.pessoas) == 10:
            return False, "\nErro! Agenda cheia"
        else:
            p = Pessoa(nome, idade)
            self.pessoas[nome] = p
            self.quantidade += 1
            return True, "\nPessoa armazenada com sucesso"
        
    def remover_pessoa(self, nome):
        if nome in self.pessoas:
            del self.pessoas[nome]
            self.quantidade -= 1
            return True, "\nPessoa removida com sucesso"
        else:
            return False, "\nPessoa não encontrada"
        
    def buscar_pessoa(self, nome):
        if nome in self.pessoas:
            return True, self.pessoas[nome]
        else:
            return False, "\nPessoa não encontrada"
        
    def imprimir_agenda(self):
        if not self.pessoas:
            return False, "\nAgenda vazia"
        else:
            for p in self.pessoas.values():
                print(f"Nome: {p.nome}\nIdade: {p.idade}")
            return True, "\nAgenda impressa com sucesso"

def menu():
    agenda = Agenda()
    while True:
        print("\n[1] - Armazenar pessoa\n[2] - Remover pessoa\n[3] - Buscar pessoa\n[4] - Imprimir agenda\n[0] - Sair")
        op = int(input("Digite a opção desejada: "))
        
        if op == 1:
            nome = input("Digite o nome da pessoa: ")
            idade = input("Digite a idade da pessoa: ")
            resultado = agenda.armazenar_pessoa(nome, idade)
            print(resultado[1])
        elif op == 2:
            nome = input("Digite o nome da pessoa: ")
            resultado = agenda.remover_pessoa(nome)
            print(resultado[1])
        elif op == 3:
            nome = input("Digite o nome da pessoa: ")
            resultado = agenda.buscar_pessoa(nome)
            if resultado[0]:
                print(f"Nome: {resultado[1].nome}\nIdade: {resultado[1].idade}")
            else:
                print(resultado[1])
        elif op == 4:
            resultado = agenda.imprimir_agenda()
            print(resultado[1])
        elif op == 0:
            break
        else:
            print("\nOpção inválida")
        
menu()