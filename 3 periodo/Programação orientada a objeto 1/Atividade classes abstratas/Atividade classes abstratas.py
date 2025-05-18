import abc 

class Conta(abc.ABC):
    def __init__(self, numero, titular, saldo = 0, limite = 1000):
        self._numero = numero
        self._titular = titular
        self._saldo = saldo
        self._limite = limite
        
    @property
    def numero(self):
        return self._numero
    
    @property
    def titular(self):
        return self._titular
    @titular.setter
    def titular(self, titular):
        self._titular = titular
    
    @property
    def saldo(self):
        return self._saldo
    @saldo.setter
    def saldo(self, saldo):
        self._saldo = saldo
        
    @property
    def limite(self):
        return self._limite
    @limite.setter
    def limite(self, limite):
        self._limite = limite
    
    @abc.abstractmethod
    def atualiza(self, taxa):
        pass

    def deposita(self, valor):
        if valor < 0:
            return False, "Não é possível depositar valores negativos"	
        else:
            self.saldo += valor
            return True, "Depósito realizado com sucesso"

    def saca(self, valor):
        if valor > self.saldo:
            return False, "Saldo insuficiente"
        elif valor < 0:
            return False, "Não é possível sacar valores negativos"
        elif valor > self.limite:
            return False, "Valor acima do limite" 
        else:
            self.saldo -= valor
            return True, "Saque realizado com sucesso"

    def __str__(self):
        return f"Numero: {self.numero}, Titular: {self.titular}, Saldo: {self.saldo}, Limite: {self.limite}"

class ContaCorrente(Conta):
    def atualiza(self, taxa):
        self.saldo += self.saldo * taxa * 2
        return self.saldo
    
    def __str__(self):
       return f"CONTA CORRENTE: Numero: {self.numero}, Titular: {self.titular}, Saldo: {self.saldo}, Limite: {self.limite}"  

class ContaPoupanca(Conta):
    def atualiza(self, taxa):
        self.saldo += self.saldo * taxa * 3
        return self.saldo
    
    def __str__(self):
        return f"CONTA POUPANÇA: Numero: {self.numero}, Titular: {self.titular}, Saldo: {self.saldo}, Limite: {self.limite}"
    
class ContaInvestimento(Conta):
    def atualiza(self, taxa):
        self.saldo += self.saldo * taxa * 5
        return self.saldo
    
    def __str__(self):
        return f"CONTA INVESTIMENTO: Numero: {self.numero}, Titular: {self.titular}, Saldo: {self.saldo}, Limite: {self.limite}"

if __name__ == '__main__':
    cc = ContaCorrente('123-4', 'Joao', 1000, 2000)
    cp = ContaPoupanca('123-5', 'Jose', 1000, 2000)
    ci = ContaInvestimento('123-6', 'Maria', 1000, 2000)

    cc.atualiza(0.01)
    cp.atualiza(0.02)
    ci.atualiza(0.05)
    ci.deposita(1000)

    print(cc.saldo)
    print(cp.saldo)
    print(ci.saldo, "\n")

    contas = [cc, cp, ci]
    for conta in contas:
        print(conta)
    print("\n")