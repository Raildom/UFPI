class Conta:
    def __init__(self, titular, numero, saldo):
        self._titular = titular
        self._numero = numero
        self._saldo = saldo

    @property
    def titular(self):
        return self._titular
    @titular.setter
    def titular(self, titular):
        self._titular = titular
    
    @property
    def numero(self):
        return self._numero

    @property
    def saldo(self):
        return self._saldo
    @saldo.setter
    def saldo(self, saldo):
        self._saldo = saldo

    def depositar(self, valor):
        self._saldo += valor

    def sacar(self, valor):
        if self._saldo >= valor:
            self._saldo -= valor
        else:
            print('Saldo insuficiente')

    def atualizar(self, taxa):
        self._saldo += self._saldo * taxa

    def __str__(self):
        return 'Titular: {}, Número: {}, Saldo: R${}'.format(self._titular, self._numero, self._saldo)


class ContaCorrente(Conta):
    def atualizar(self, taxa):
        super().atualizar(taxa * 2)

    def depositar(self, valor):
        super().depositar(valor - 0.10)

class ContaPoupanca(Conta):
    def atualizar(self, taxa):
        super().atualizar(taxa * 3)

class AtualizadorDeContas:
    def __init__(self, selic, saldo_total=0):
        self._selic = selic
        self._saldo_total = saldo_total

    @property
    def selic(self):
        return self._selic
    @selic.setter
    def selic(self, selic):
        self._selic = selic

    @property
    def saldo_total(self):
        return self._saldo_total
    @saldo_total.setter
    def saldo_total(self, saldo_total):
        self._saldo_total = saldo_total

    def roda(self, contas):
        for conta in contas:
            print('Saldo da conta antes da atualização: R${}'.format(conta.saldo))
            conta.atualizar(self._selic)
            self._saldo_total += conta.saldo
            print("Saldo Final após atualização: R${}".format(conta.saldo))
        print("Saldo total após atualizar todas as contas: R${}".format(self._saldo_total))

def menu():
    cc = ContaCorrente('João', '11-33', 1000)
    cp = ContaPoupanca('Maria', '11-23', 1000)
    contas = [cc, cp]
    atualizador = AtualizadorDeContas(0.01)

    while True:
        print("\n===== Menu de Opções =====")
        print("1. Exibir saldos das contas")
        print("2. Depositar em uma conta")
        print("3. Sacar de uma conta")
        print("4. Atualizar contas")
        print("5. Sair")
        
        opcao = input("Escolha uma opção: ")

        if opcao == '1':
            print(cc)
            print(cp)
        elif opcao == '2':
            tipo_conta = input("Digite o tipo de conta (corrente/poupanca): ").lower()
            valor = float(input("Digite o valor do depósito: R$"))
            if tipo_conta == 'corrente':
                cc.depositar(valor)
            elif tipo_conta == 'poupanca':
                cp.depositar(valor)
            else:
                print("Tipo de conta inválido.")
        elif opcao == '3':
            tipo_conta = input("Digite o tipo de conta (corrente/poupanca): ").lower()
            valor = float(input("Digite o valor do saque: R$"))
            if tipo_conta == 'corrente':
                cc.sacar(valor)
            elif tipo_conta == 'poupanca':
                cp.sacar(valor)
            else:
                print("Tipo de conta inválido.")
        elif opcao == '4':
            atualizador.roda(contas)
        elif opcao == '5':
            print("Saindo... Até logo!")
            break
        else:
            print("Opção inválida, tente novamente.")

if __name__ == "__main__":
    menu()
