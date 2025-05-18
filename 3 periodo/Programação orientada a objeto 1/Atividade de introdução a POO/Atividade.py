import random
import datetime

class Cliente:
    def __init__(self, nome, cpf):
        self._nome = nome
        self._cpf = cpf
    
    @property
    def nome(self):
        return self._nome

    @nome.setter
    def nome(self, nome):
        if nome.strip():
            self._nome = nome
        else:
            print("Nome não pode ser vazio.")
    
    @property
    def cpf(self):
        return self._cpf

class Conta:
    total_contas = 0
    numeros_usados = set()
    contas = {}
    
    def __init__(self, titular, saldo = 0):
        self._titular = titular
        self._numero = self.gerar_numero_conta()
        self._saldo = saldo
        self._historico = Historico()
        Conta.total_contas += 1
        Conta.contas[self._numero] = self
    
    @property
    def historico(self):
        return self._historico
    
    @property
    def saldo(self):
        return self._saldo
    
    @saldo.setter
    def saldo(self, saldo):
        if saldo < 0:
            print("\nSaldo não pode ser negativo\n")
        else:
            self._saldo = saldo
            
    @property
    def numero(self):
        return self._numero
    
    @property
    def titular(self):
        return self._titular

    def gerar_numero_conta(self):
        while True:
            numero = f"{random.randint(0, 999):03d}"
            if numero not in Conta.numeros_usados:
                Conta.numeros_usados.add(numero)
                return str(numero)
    
    def sacar(self, valor):
        if valor > self.saldo:
            print("\nSaldo insuficiente\n")
            self.historico.add_transacao(f"Tentativa de saque de {valor} falhou! Saldo insuficiente")
            return False, "Erro ao sacar! Saldo insuficiente"
        elif valor < 0:
            print("\nValor inválido\n")
            self.historico.add_transacao(f"Tentativa de saque de {valor} falhou! Valor inválido")
            return False, "Erro ao sacar! Valor inválido"
        else:
            self.saldo -= valor
            print("\nSaque realizado com sucesso\n")
            self.historico.add_transacao(f"Saque de {valor} realizado com sucesso")
            return True, f"Saque de {valor} realizado com sucesso!"
        
    def depositar(self, valor):
        if valor < 0:
            print("\nValor inválido\n")
            self.historico.add_transacao(f"Tentativa de deposito de {valor} falhou! Valor inválido")
            return False, "Erro ao depositar! Valor inválido"
        else:
            self.saldo += valor
            print("\nDeposito realizado com sucesso\n")
            self.historico.add_transacao(f"Deposito de {valor} realizado com sucesso")
            return True, f"Deposito de {valor} realizado com sucesso!"
        
    def transferir(self, conta_destino, valor):
        if self.saldo < valor:
            print("Erro ao transferir! Saldo insuficiente")
            self.historico.add_transacao(f"Erro ao transferir! Saldo insuficiente\nSaldo: {self.saldo}\nValor: {valor}")
            return False, "Erro ao transferir! Saldo insuficiente"
        elif valor < 0:
            print("Erro ao transferir! Valor inválido")
            self.historico.add_transacao(f"Erro ao transferir! Valor inválido\nSaldo: {self.saldo}\nValor: {valor}")
            return False, "Erro ao transferir! Valor inválido"
        else:
            self.saldo -= valor
            conta_destino.saldo += valor
            self.historico.add_transacao(f"Transferência de {valor} para {conta_destino.titular.nome} realizada com sucesso")
            conta_destino.historico.add_transacao(f"Recebimento de {valor} de {self.titular.nome} realizado com sucesso")
            return True, f"Transferência de {valor} para {conta_destino.titular.nome} realizada com sucesso"
       
    def listar_contas():
        if not Conta.contas:
            print("\nNenhuma conta cadastrada\n")
            return False, "Nenhuma conta cadastrada"
        
        resultado = "\nContas cadastradas:\n"
        for conta in Conta.contas.values():
            resultado += f"\nTitular: {conta.titular.nome}\nConta: {conta.numero}\nSaldo: R${conta.saldo:.2f}\n"
        print(resultado)
            
    def excluir_conta(self):
        if self.numero in Conta.contas:
            self.historico.add_transacao(f"Conta de número: {self.numero} excluída com sucesso!")
            del Conta.contas[self.numero]
            print("\nConta excluída com sucesso!\n")
            return True, f"Conta de número: {self.numero} excluída com sucesso!"
        else:
            print("\nConta não encontrada!\n")
            self.historico.add_transacao(f"Erro ao excluir conta! Conta não encontrada")
            return False, "Erro ao excluir conta! Conta não encontrada"
        
        
class Historico:
    def __init__(self):
        self._data_abertura = datetime.datetime.now()
        self._transacoes = []
        
    @property
    def data_abertura(self):
        return self._data_abertura
    
    @property   
    def transacoes(self):
        return self._transacoes
    
    def add_transacao(self, t):
        self.transacoes.append(t)
    
    def listar_transacoes(self):
        print(f"Data de abertura: {self._data_abertura}")
        for t in self.transacoes:
            print(t)

def menu():
    while True:
        print("\n[1] - Criar conta")
        print("[2] - Listar contas")
        print("[3] - Sacar")
        print("[4] - Depositar")
        print("[5] - Transferir")
        print("[6] - Excluir conta")
        print("[0] - Sair")
        op = int(input("Escolha uma opção: "))
        
        if op == 1:
            nome = input("\nDigite o nome do titular: ")
            cpf = input("Digite o CPF do titular: ")
            cliente = Cliente(nome, cpf)
            c = Conta(cliente)
            print(f"\nConta criada com sucesso!\nNumero da conta: {c.numero}")
        elif op == 2:
            Conta.listar_contas()
        elif op == 3:
            numero = input("Digite o numero da conta: ")
            if numero in Conta.contas:
                valor = float(input("Digite o valor a ser sacado: "))
                Conta.contas[numero].sacar(valor)
            else:
                print("Conta não encontrada!")
        elif op == 4:
            numero = input("Digite o numero da conta: ")
            if numero in Conta.contas:
                valor = float(input("Digite o valor a ser depositado: "))
                Conta.contas[numero].depositar(valor)
            else:
                print("Conta não encontrada!")
        elif op == 5:
            numero_origem = input("Digite o numero da conta de origem: ")
            numero_destino = input("Digite o numero da conta de destino: ")
            if numero_origem in Conta.contas and numero_destino in Conta.contas:
                valor = float(input("Digite o valor a ser transferido: "))
                Conta.contas[numero_origem].transferir(Conta.contas[numero_destino], valor)
            else:
                print("Conta de origem ou destino não encontrada!")
        elif op == 6:
            numero = input("Digite o numero da conta: ")
            if numero in Conta.contas:
                Conta.contas[numero].excluir_conta()
            else:
                print("Conta não encontrada!")
        elif op == 0:
            break
        else:
            print("Opção inválida.")

menu()