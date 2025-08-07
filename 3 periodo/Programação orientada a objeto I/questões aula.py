# # inicio = int(input("Digite o início do intervalo: "))
# # fim = int(input("Digite o fim do intervalo: "))

# # soma = 0

# # for i in range(inicio, fim + 1):
# #     if i % 2 == 0:
# #         soma += i
# # print(f"A soma dos números do intervalo de {inicio} e {fim} é {soma}")

# # ############################################################################################################################################

# # print("1 - OLA\n2 - COMO VAI?\n3 - sair")
# # opcao = int(input("Digite a opção desejada: "))

# # while(True):
# #     if(opcao == 1):
# #         print("OLA")
# #     elif(opcao == 2):
# #         print("COMO VAI?")
# #     elif(opcao == 3):
# #         break
# #     else:
# #         print("Opção inválida")
# #     opcao = int(input("\nDigite a opção desejada: "))

# #############################################################################################################################################

# # while(True):
# #     try:
# #         a = float(input("Digite um número: "))
# #         b = float(input("Digite outro número: "))
# #         print(a / b)
# #         break
# #     except:
# #         continue

# #############################################################################################################################################

# # def soma(a, b):
# #     return a + b

# # def subtração(a, b):
# #     return a - b

# # def multiplicacao(a, b):
# #     return a * b

# # def divisao(a, b):
# #     return a / b

# # while True:
# #     try:
# #         num1 = float(input("Digite um número: "))
# #         num2 = float(input("Digite outro número: "))
# #         break
# #     except:
# #         continue
# # resultado = 0.0

# # while True:
# #     print("[1] SOMA\n[2] SUBTRAÇÂO\n[3] MULTIPLICAÇÂO\n[4] DIVISÂO")
# #     opcao = int(input())
# #     if opcao == 1:
# #         resultado = soma(num1, num2)
# #         break
# #     elif opcao == 2:
# #         resultado = subtração(num1, num2)
# #         break
# #     elif opcao == 3:
# #         resultado = multiplicacao(num1, num2)
# #         break
# #     elif opcao == 4:
# #         if num2 != 0:
# #             resultado = divisao(num1, num2)
# #             break
# #         else:
# #             print("Não pode divisão por 0.\n")
# #             continue
# #     else:
# #         print("ERRO!\n")
# # print(f"RESULTADO: {resultado}")

# #############################################################################################################################################

# # nome = "tESte"

# # print(nome.split())    
# # print(nome.capitalize())
# # # nome = nome.capitalize()
# # print(nome.swapcase())
# # print(nome.count(nome))
# # print(nome.upper())
# # print(nome.lower())

# #############################################################################################################################################

# # frase = input("Digite uma frase ")

# # while True:
# #     while True:
# #         try:
# #             print("\n[1] FRASE ORIGINAL\n[2] TODA MAIUSCULA\n[3] TODA MINUSCULA\n[4] PRIMEIRA LETRA MAIUSCULA\n[5] DIGITAR NOVA FRASE\n[6] SAIR\n")
# #             opcao = int(input(": "))
# #             break
# #         except:
# #             continue
# #     if opcao == 1:
# #         print(frase)
# #     elif opcao == 2:
# #         print(frase.upper())
# #     elif opcao == 3:
# #         print(frase.lower())
# #     elif opcao == 4:
# #         print(frase.capitalize())
# #     elif opcao == 5:
# #         frase = input("Digite a nova frase: ")
# #     elif opcao == 6:
# #         break
# #     else:
# #         print("Opção inválida!")
    
# #############################################################################################################################################

# # lista = [1.2, 2, 4, 1, 10]

# # print(lista)


# # lista.append(2)
# # print(lista)
# # lista.append(29)
# # print(lista)
# # # lista.insert(1, "teste")
# # print(lista)
# # lista.pop(1)
# # lista.sort()

# # print(lista)

# # print(lista[0:])

# # for i in range(lista):
# #     print(i)

# #############################################################################################################################################
# # lista = []
# # soma = 0

# # while True:
# #     try:
# #         elemento = float(input("Digite um numero: "))
# #         if elemento < 0:
# #             break
# #         lista.append(elemento)
# #         soma += elemento
# #     except:
# #         continue
    
# # soma / len(lista)
# # print(soma / len(lista))

# #############################################################################################################################################

# # lista = [1, 2, 3, 4, 5, 1, 2, 3, 1, 1]
# # contador = 0

# # while True:
# #     try:
# #         busca = int(input("Digite o numero que deseja buscar: "))
# #         break
# #     except:
# #         continue
# # for i in range(len(lista)):
# #     if busca == lista[i]:
# #         contador += 1     
# # print(f": {contador}")

# #############################################################################################################################################
# # lista = []

# # for i in range(5):
# #     while True:
# #         try:
# #             num = int(input(f"Digite o {i + 1} numero: "))        
# #             break
# #         except:
# #             continue
# #     lista.append(num)
# # lista.sort()
# # print(lista)
# # lista.reverse()
# # print(lista)

# #############################################################################################################################################

# # lista = []

# # def IsPar(num):
# #     return num % 2 == 0 and num != 0
# # def IsImpar(num):
# #     return num % 2 != 0
# # def IsZero(num):
# #     return num == 0

# # while True:
# #     while True:    
# #         try:
# #             num = int(input("Digite o numero inicial: "))
# #             break
# #         except:
# #             continue
# #     if num < 0:
# #         break
# #     else:
# #         lista.append(num)
# #     par = list(filter(IsPar, lista))
# #     impar = list(filter(IsImpar, lista))
# #     zeros = list(filter(IsZero, lista))
# # completo = par + zeros + impar
# # print(completo)

# #############################################################################################################################################

# # import functools
# # lista = [1, 2, 3, 4, 5, 6]

# # def dobro(x):
# #     return x * 2
# # def IsPar(x):
# #     return x % 2 == 0
# # def soma(x, y):
# #     return x + y

# # pares = filter(IsPar, lista)
# # dobro_pares = map(dobro, pares)
# # resultado = functools.reduce(soma, dobro_pares)

# # print(resultado)

# #############################################################################################################################################

# # import functools as ft
# # lista = [1, 2, 3, 4, 5, 6]

# # pares = filter(lambda x: x % 2 == 0 and x != 0, lista)
# # dobro = map(lambda x: x * 2, pares)
# # resultado = ft.reduce(lambda x, y: x + y, dobro)
# # print(resultado) 

# #############################################################################################################################################

# # lista = []
# # while True:
# #     x = int(input("Digite um numero: "))
# #     if(x < 0):
# #         break
# #     lista.append(x)
# # zeros = list(filter(lambda x: x == 0, lista))
# # pares = list(filter(lambda x: x % 2 == 0 and x != 0, lista))
# # impares = list(filter(lambda x: x % 2 != 0, lista))

# # resultado = pares + zeros + impares
# # print(resultado)

# ########################################################## NÚMEROS PRIMOS ###################################################################################
# ######################################################## LISTA COMPREENSIVAS ###############################################################

# # while True:
# #     num = int(input("Digite um numero: "))
# #     primo = [x for x in range(1, num + 1) if num % x == 0]
    
# #     if(len(primo) > 2):
# #         print("Não é primo")
# #     elif len(primo) <= 2 and len(primo) > 0 and len(primo) != 1:
# #         print("É primo")
# #     else:
# #         print("Não é primo")

# #############################################################################################################################################

# # lista = [3, 2, 1]
# # tuple = (1, 2, 3, lista)
# # lista.append(29)

# # print(tuple)
# #############################################################################################################################################

# # conjunto = {1, 2, 3, 4, 5, 4, 5, 2}
# # print(conjunto)
# # elemento1 = set("abacate")
# # elemento2 = set("abacaxi")

# # print(elemento1)
# # print(elemento2)

# # difereca = elemento1 - elemento2
# # uniao = elemento1 | elemento2
# # intersecao = elemento1 & elemento2
# # simetrica = elemento1 ^ elemento2

# # print("Diferença: ", difereca) 
# # print("União: ", uniao)
# # print("Interseção: ", intersecao)
# # print("Simétrica: ", simetrica)

# #############################################################################################################################################

# # turma1 = ["Flavio", "Joao", "Maria", "Pedro"]
# # turma2 = ["Ana", "Julia", "Flavio", "Pedro"]

# # turma1 = set(turma1)
# # turma2 = set(turma2)

# # print(f"Todos os alunos: {turma1 | turma2}")

# # print(f"Alunos presentes nas duas turmas: {turma1 & turma2}")
# # print(f"Alunos presentes apenas na turma 1: {turma1 - turma2}")

# #############################################################################################################################################

# # dicionario = {
# #     "nome": "Flavio", 
# #     "idade": 20, 
# #     "cidade": "São Paulo"}

# # dicionario["estado"] = "gasoso"
# # print(dicionario["estado"])

# # for chave in dicionario.keys():        
# #     print(chave)

# # print(dicionario.keys())

# # if "nome" in dicionario:
# #     print("Existe")
# # else:
# #     print("Não existe") 
# # dicionario.clear()
# # print(dicionario)

# # dicionario2 = {1: "a", 2: "b", 3: "c"}
# # dicionario2 = dicionario.copy()
# # print(dicionario2)
# # dicionario2 = {
# #     "nome": "Flavio", 
# #     "idade": 20, 
# #     "cidade": "São Paulo"}
# # print(dicionario2.get("nome"))

# #############################################################################################################################################

# # dicionario = {
# #     "brasil": "brasilia", 
# #     "argentina": "buenos aires", 
# #     "paraguai": "assunção",
# #     "uruguai": "montevideu",
# #     "chile": "santiago",
# #     "peru": "lima"}

# # pais = input("Digite o nome do pais: ")

# # if pais in dicionario:
# #     print(dicionario[pais])
# # else:
# #     print("Não existe")

# #############################################################################################################################################

# # class Aluno():
# #     def __init__(self, nome, matricula):
# #         self.nome = nome
# #         self.matricula = matricula

# #     def imprimir(self):
# #         print(self.nome)
# #         print(self.matricula)

# # c1.imprimir()
# # c1.depositar(29)
# # c1.imprimir()
# # c1.sacar(30)
# # c1.imprimir()
# # a1 = Aluno("raildom", "123")
# # a2 = Aluno("maria", "321")
# # a1.imprimir()
# # a2.imprimir()

# #############################################################################################################################################

# # import datetime

# # class Historico():
# #     def __init__(self):
# #         self.DataAbertura = datetime.datetime.now()
# #         self.transacoes = []
        
# #     def add_transacao(self, t):
# #         self.transacoes.append(t)
        
# #     def listar_transacoes(self):
# #         print(f"Data de abertura: {self.DataAbertura}")
# #         for t in self.transacoes:
# #             print(t)

# # class Cliente():
# #     def __init__(self, nome, cpf):
# #         self.nome = nome
# #         self.cpf = cpf
        
# #     def imprimir(self):
# #         print(f"Nome: {self.nome}\nCPF: {self.cpf}")
        
        
# # class Conta():
# #     def __init__(self, titular, numero, saldo = 100):
# #         self.numero = numero
# #         self.titular = titular
# #         self.saldo = saldo
# #         self.historico = Historico()
        
# #     def depositar(self, valor):
# #         if valor > 0:
# #             self.saldo += valor
# #             return True, f"Deposito de {valor} realizado com sucesso\n"
# #         else:
# #             return False, "Erro ao depositar, saldo negativo!\n"
        
# #     def imprimir(self):
# #         self.titular.imprimir()
# #         print(f"Número da conta: {self.numero}\nSaldo: {self.saldo:.2f}\n")
    
# #     def sacar(self, valor):
# #         if self.saldo >= valor:
# #             self.saldo -= valor
# #             return True, f"Valor de {valor} sacado com sucesso!\n"
# #         else:
# #             return False, "Erro ao sacar, saldo insuficiente!\n"
        
# #     def transferir(self, ContaDestino, valor):
# #         if self.saldo < valor:
# #             return False, "Erro ao tranferir, saldo insuficiente"
# #         elif valor < 0:
# #             return False, "Erro ao tranferir, valor de tranferencia negativo"
# #         else:
# #             self.saldo -= valor
# #             ContaDestino.saldo += valor
# #             return True, f"tranferencia de {valor} para {ContaDestino.titular.nome} realizada com sucesso"

# # cliente1 = Cliente("flavio", "123")
# # cliente2 = Cliente("henrique", "321")

# # c1 = Conta(cliente1, 111)
# # c2 = Conta(cliente2, 222)

# # while True:
# #     op = int(input("\n[1] - DEPOSITAR\n[2] - SACAR\n[3] - EXTRATO\n[4] - TRANSFERIR\n[5] - SAIR\nDigite a opção desejada: "))
# #     if op == 1:
# #         nome = input("Digite o nome: ")
# #         valor = float(input("Digite o valor do deposito: "))
# #         if nome == c1.titular.nome:
# #             retorno = c1.depositar(valor)
# #         elif nome == c2.titular.nome:
# #             retorno = c2.depositar(valor)
# #         else:
# #             retorno = False, "Cliente não encontrado!"
# #         print(retorno[1])
        
# #     elif op == 2:
# #         nome = input("Digite o nome: ")
# #         valor = float(input("Digite o valor a sacar: "))
# #         if nome == c1.titular.nome:
# #             retorno = c1.sacar(valor)
# #         elif nome == c2.titular.nome:
# #             retorno = c2.sacar(valor)
# #         else:
# #             retorno = False, "Cliente não encontrado!"
# #         print(retorno[1])
        
# #     elif op == 3:
# #         c1.imprimir()
# #         c2.imprimir()
        
# #     elif op == 4:
# #         valor = float(input("Digite o valor da tranferencia: "))
# #         retorno = c1.transferir(c2, valor)
# #         print(f"{retorno[1]}")  
         
# #     elif op == 5:
# #         break


# #############################################################################################################################################

# # import datetime

# # class Historico():
# #     def __init__(self):
# #         self.DataAbertura = datetime.datetime.now()
# #         self.transacoes = []
        
# #     def add_transacao(self, t):
# #         self.transacoes.append(t)
        
# #     def listar_transacoes(self):
# #         print(f"Data de abertura: {self.DataAbertura}")
# #         for t in self.transacoes:
# #             print(t)

# # class Cliente():
# #     def __init__(self, nome, cpf):
# #         self.nome = nome
# #         self.cpf = cpf
        
# #     def imprimir(self):
# #         print(f"Nome: {self.nome}\nCPF: {self.cpf}")
              
# # class Conta():
# #     def __init__(self, titular, numero, saldo = 0):
# #         self.numero = numero
# #         self.titular = titular
# #         self.saldo = saldo
# #         self.historico = Historico()
        
# #     def depositar(self, valor):
# #         if valor > 0:
# #             self.saldo += valor
# #             self.historico.add_transacao(f"Depósito de {valor} realizado com sucesso")
# #             return True, f"Depósito de {valor} realizado com sucesso\n"
# #         else:
# #             return False, "Erro ao depositar, valor negativo!\n"
        
# #     def imprimir(self):
# #         self.titular.imprimir()
# #         print(f"Número da conta: {self.numero}\nSaldo: {self.saldo:.2f}\n")
    
# #     def sacar(self, valor):
# #         if self.saldo >= valor:
# #             self.saldo -= valor
# #             self.historico.add_transacao(f"Saque de {valor} realizado com sucesso")
# #             return True, f"Valor de {valor} sacado com sucesso!\n"
# #         else:
# #             return False, "Erro ao sacar, saldo insuficiente!\n"
        
# #     def transferir(self, ContaDestino, valor):
# #         if self.saldo < valor:
# #             return False, "Erro ao transferir, saldo insuficiente"
# #         elif valor < 0:
# #             return False, "Erro ao transferir, valor de transferência negativo"
# #         else:
# #             self.saldo -= valor
# #             ContaDestino.saldo += valor
# #             self.historico.add_transacao(f"Transferência de {valor} para {ContaDestino.titular.nome} realizada com sucesso")
# #             ContaDestino.historico.add_transacao(f"Recebimento de {valor} de {self.titular.nome} realizado com sucesso")
# #             return True, f"Transferência de {valor} para {ContaDestino.titular.nome} realizada com sucesso"

# # cliente1 = Cliente("flavio", "123")
# # cliente2 = Cliente("henrique", "321")

# # c1 = Conta(cliente1, 111)
# # c2 = Conta(cliente2, 222)

# # while True:
# #     op = int(input("\n[1] - DEPOSITAR\n[2] - SACAR\n[3] - EXTRATO\n[4] - TRANSFERIR\n[5] - HISTÓRICO\n[6] - SAIR\nDigite a opção desejada: "))
# #     if op == 1:
# #         nome = input("Digite o nome: ")
# #         valor = float(input("Digite o valor do depósito: "))
# #         if nome == c1.titular.nome:
# #             retorno = c1.depositar(valor)
# #         elif nome == c2.titular.nome:
# #             retorno = c2.depositar(valor)
# #         else:
# #             retorno = False, "Cliente não encontrado!"
# #         print(retorno[1])
        
# #     elif op == 2:
# #         nome = input("Digite o nome: ")
# #         valor = float(input("Digite o valor a sacar: "))
# #         if nome == c1.titular.nome:
# #             retorno = c1.sacar(valor)
# #         elif nome == c2.titular.nome:
# #             retorno = c2.sacar(valor)
# #         else:
# #             retorno = False, "Cliente não encontrado!"
# #         print(retorno[1])
        
# #     elif op == 3:
# #         c1.imprimir()
# #         c2.imprimir()
        
# #     elif op == 4:
# #         valor = float(input("Digite o valor da transferência: "))
# #         retorno = c1.transferir(c2, valor)
# #         print(f"{retorno[1]}")  
        
# #     elif op == 5:
# #         nome = input("Digite o nome: ")
# #         if nome == c1.titular.nome:
# #             c1.historico.listar_transacoes()
# #         elif nome == c2.titular.nome:
# #             c2.historico.listar_transacoes()
# #         else:
# #             print("Cliente não encontrado!")
# #     elif op == 6:
# #         break

# #############################################################################################################################################

# # class Conta():
# #     total_contas = 0
    
# #     def __init__(self, titular, numero):
# #         self._titular = titular
# #         self._numero = numero
# #         self._saldo = 0
# #         Conta.total_contas += 1
        
# #         #self == atributo do objeto
# #         #Nome da classe, no caso "Conta" para atributos de classe (globais)
        
# #     @property #GET | Visualiza
# #     def saldo(self):
# #         return self._saldo
    
# #     @saldo.setter #SET | altera
# #     def saldo(self, saldo):
# #         if saldo < 0:
# #             print("\nSaldo não pode ser negativo\n")
# #         else:
# #             self._saldo = saldo
            
# #     @property
# #     def numero(self):
# #         return self._numero
    
# #     @numero.setter
# #     def numero(self, numero):
# #         print("\nNumero da conta não pode ser alterado!\n")
# #         # self._numero = numero
        
# #     @property
# #     def titular(self):
# #         return self._titular 
   
# #     @titular.setter
# #     def titular(self, titular):
# #        self._titular = titular
       
# #     def imprimir(self):
# #         print(f"\nTitular: {self.titular}\nNumero: {self.numero}\nSaldo: {self.saldo}\n")
        
# # c1 = Conta("flavio", "123")
# # c1.saldo = 1.99
# # # print(c1.saldo)
# # # c1.numero = "111"
# # # print(c1.numero)
# # c1.imprimir()


# #############################################################################################################################################

# class Pessoa():
#     def __init__(self, nome, cpf):
#         self._nome = nome
#         self._cpf = cpf
        
#     @property
#     def nome(self):
#         return self._nome  
#     @property
#     def cpf(self):
#         return self._cpf
    
#     def imprimir(self):
#         print(f"\nNome: {self.nome}\nCPF: {self.cpf}")
        
# class Cliente(Pessoa):
#     def __init__(self, nome, cpf):
#         super().__init__(nome, cpf)
        
# class Atendente(Pessoa):
#     def __init__(self, nome, cpf, telefone):
#         super().__init__(nome, cpf)
#         self._telefone = telefone
        
#     @property
#     def telefone(self):
#         return self._telefone
#     @telefone.setter
#     def telefone(self, telefone):
#         self._telefone = telefone
    
# class Gerente(Pessoa):
#     def __init__(self, nome, cpf, senha, listaSetores):
#         super().__init__(nome, cpf)
#         self._senha = senha
#         self._listaSetores = listaSetores
        
#     @property
#     def senha(self):
#         return self._senha
#     @senha.setter
#     def senha(self, senha):
#         self._senha = senha 
        
#     @property
#     def listaSetores(self):
#         return self._listaSetores 
#     @listaSetores.setter
#     def listaSetores(self, listaSetores):
#         self._listaSetores = listaSetores
        
#     def imprimir(self):
#         super().imprimir()
#         print(f"Senha: {self.senha}\nLista de setores: {self.listaSetores}\n")
        
# def main():
#     c = Cliente("irineu", "123")
#     a = Atendente("maria", "456", "9999-9999")
#     g = Gerente("flavio", "789", "1234", ["vendas", "estoque"])
    
#     c.imprimir()
#     a.imprimir()
#     g.imprimir()
    
# main()

# #############################################################################################################################################

# import abc

# class Funcionario(abc.ABC):
#     def __init__(self, nome, salario, cpf):
#         self._nome = nome
#         self._salario = salario
#         self._cpf = cpf
        
#     @property
#     def nome(self):
#         return self._nome
#     @property
    
#     def cpf(self):
#         return self._cpf
    
#     @property
#     def salario(self):
#         return self._salario
#     @salario.setter
#     def salario(self, salario):
#         self._salario = salario
        
#     @abc.abstractmethod
#     def get_bonificacao(self):
#         pass
    
#     def __str__(self):
#         return f"\nNome: {self.nome}\nCPF: {self.cpf}\nSalario: {self.salario}\n"
    
# class Atendente(Funcionario):
#     def __init__(self, nome, salario, cpf):
#         super().__init__(nome, salario, cpf)
        
#     def get_bonificacao(self):
#         return self.salario * 0.5
    
#     def __str__(self):
#         return f"\nNome: {self.nome}\nCPF: {self.cpf}\nSalario: {self.salario}\n"
    
# class Gerente(Funcionario):
#     def __init__(self, nome, salario, cpf):
#         super().__init__(nome, salario, cpf)
        
#     def get_bonificacao(self):
#         return self.salario * 0.4 + 2000
    
#     def __str__(self):
#         return f"\nNome: {self.nome}\nCPF: {self.cpf}\nSalario: {self.salario}\n"
    
# class Controle_bonificacao():
#     def __init__(self):
#         self._total_bonificacao = 0
            
#     @property
#     def total_bonificacao(self):
#         return self._total_bonificacao
#     @total_bonificacao.setter
#     def total_bonificacao(self, total_bonificacao):
#         self._total_bonificacao = total_bonificacao
        
#     def registrar(self, funcionario):
#         if isinstance(funcionario, Funcionario):
#             self.total_bonificacao += funcionario.get_bonificacao()
#         else:
#             print("\nFuncionário não é do tipo Funcionário\n")
        
#     def __str__(self):
#         return f"Total de bonificação: {self.total_bonificacao}"
      
          
# a = Atendente("maria", 1000, "456")
# g = Gerente("henrique", 1000, "789")

# total_bonificacao = Controle_bonificacao()

# total_bonificacao.registrar(a)
# total_bonificacao.registrar(g)

# print(a)
# print(g)
# print(total_bonificacao)

#############################################################################################################################################

import abc

class Autentica(abc.ABC):
    @abc.abstractmethod
    def autentica(self, senha):
        pass

class Funcionario(Autentica):
    def __init__(self, nome, cpf, senha):
        self.nome = nome
        self.cpf = cpf
        self.senha = senha
        

        
class Secretario(Funcionario):
    def __init__(self, nome, cpf, senha):
        super().__init__(nome, cpf, senha)
        
    def autentica(self, senha):
        if self.senha == senha:
            return True
        else:
            return False
        
    def __str__(self):
        return f"Nome: {self.nome}\nCPF: {self.cpf}"
    
class sistema():
    def login(self, obj):
        if isinstance(obj, Autentica):
            if obj.autentica("123"):
                print("login sucesso")
            else:
                print("Login inválido")
        else:
            print("Esse objeto não é autenticavel")
        
si = sistema()
secret = Secretario("irineu", "321", "123")

si.login(secret)



    
    

#############################################################################################################################################

#############################################################################################################################################