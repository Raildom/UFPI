import datetime

class Pessoa:
    def __init__(self, nome, data_nascimento, altura):
        self._nome = nome
        self._data_nascimento = datetime.datetime.strptime(data_nascimento, '%d%m%Y')
        self._altura = altura

    @property
    def nome(self):
        return self._nome
    @nome.setter
    def nome(self, nome):
        self._nome = nome

    @property
    def data_nascimento(self):
        return self._data_nascimento
    @data_nascimento.setter
    def data_nascimento(self, data_nascimento):
        print("Data de nascimento não pode ser alterada")

    @property
    def altura(self):
        return self._altura
    @altura.setter
    def altura(self, altura):
        self._altura = altura

    def imprimir_dados(self):
        print(f"\nNome: {self.nome}\nData de nascimento: {self.data_nascimento.strftime('%d-%m-%Y')}\nAltura: {self.altura}\nIdade: {self.calcula_idade()}")

    def calcula_idade(self):
        data_atual = datetime.datetime.now()
        idade = data_atual.year - self._data_nascimento.year
        if data_atual.month < self.data_nascimento.month or (data_atual.month == self.data_nascimento.month and data_atual.day < self.data_nascimento.day):
            idade -= 1
        return idade

def menu():
    pessoa = None
    
    while True:
        print("\n[1] - Cadastrar pessoa")
        print("[2] - Imprimir dados")
        print("[3] - Sair")
        
        opcao = int(input("Digite a opção desejada: "))

        if opcao == 1:
            nome = input("\nDigite o nome: ")
            data_nascimento = input("OBS: A data de nascimento deve obrigatoriamente ser digitada como (dd-mm-aaaa) sem caracteres a menos!\nDigite a data de nascimento: ")
            altura = float(input("Digite a altura: "))
            pessoa = Pessoa(nome, data_nascimento, altura)
        elif opcao == 2:
            if pessoa:
                pessoa.imprimir_dados()
            else:
                print("\nNenhuma pessoa cadastrada.")
        elif opcao == 3:
            break
        else:
            print("Opção inválida!")

menu()