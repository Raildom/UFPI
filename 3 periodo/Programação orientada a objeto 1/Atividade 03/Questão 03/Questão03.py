class Elevador:
    def __init__(self, total_andares, capacidade_elevador, andar_atual=0, quantidade_pessoas=0):
        self._andar_atual = andar_atual
        self._total_andares = total_andares
        self._capacidade_elevador = capacidade_elevador
        self.quantidade_pessoas = quantidade_pessoas

    @property
    def andar_atual(self):
        return self._andar_atual
    @andar_atual.setter
    def andar_atual(self, andar_atual):
        self._andar_atual = andar_atual

    @property
    def total_andares(self):
        return self._total_andares
    @total_andares.setter
    def total_andares(self, total_andares):
        self._total_andares = total_andares

    @property
    def capacidade_elevador(self):
        return self._capacidade_elevador
    @capacidade_elevador.setter
    def capacidade_elevador(self, capacidade_elevador):
        self._capacidade_elevador = capacidade_elevador

    @property
    def pessoas(self):
        return self.quantidade_pessoas
    @pessoas.setter
    def pessoas(self, pessoas):
        self.quantidade_pessoas = pessoas

    def entrar(self):
        if self.quantidade_pessoas < self._capacidade_elevador:
            self.quantidade_pessoas += 1
            return True, "Uma pessoa entrou no elevador."
        else:
            return False, "O elevador está cheio"

    def sair(self):
        if self.quantidade_pessoas > 0:
            self.quantidade_pessoas -= 1
            return True, "Uma pessoa saiu do elevador."
        else:
            return False, "O elevador está vazio"

    def subir(self):
        if self._andar_atual < self._total_andares:
            self._andar_atual += 1
            return True, f"O elevador subiu para o andar {self._andar_atual}º."
        else:
            return False, "O elevador já está no último andar"

    def descer(self):
        if self._andar_atual > 0:
            self._andar_atual -= 1
            return True, f"O elevador desceu para o andar {self._andar_atual}º."
        else:
            return False, "O elevador já está no térreo"

def menu():
    total_andares = int(input("Digite o total de andares do prédio: "))
    capacidade_elevador = int(input("Digite a capacidade do elevador: "))
    elevador = Elevador(total_andares, capacidade_elevador)

    while True:
        print("\n1 - Entrar")
        print("2 - Sair")
        print("3 - Subir")
        print("4 - Descer")
        print("0 - Sair do programa")
        
        op = int(input("Digite a opção desejada: "))

        if op == 1:
            res = elevador.entrar()
            print(res[1])
        elif op == 2:
            res = elevador.sair()
            print(res[1])
        elif op == 3:
            res = elevador.subir()
            print(res[1])
        elif op == 4:
            res = elevador.descer()
            print(res[1])
        elif op == 0:
            break
        else:
            print("Opção inválida")

menu()