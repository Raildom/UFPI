class Carro:
    def __init__(self, modelo, ano, placa, emprestado=False):
        self._modelo = modelo
        self._ano = ano
        self._placa = placa
        self._emprestado = emprestado

    @property
    def modelo(self):
        return self._modelo

    @property
    def ano(self):
        return self._ano

    @property
    def placa(self):
        return self._placa

    @property
    def emprestado(self):
        return self._emprestado

    @emprestado.setter
    def emprestado(self, emprestado):
        self._emprestado = emprestado

    def __str__(self):
        return f"Modelo: {self.modelo}, Ano: {self.ano}, Placa: {self.placa}"


class Emprestimo:
    def __init__(self):
        self._emprestimos = []

    @property
    def emprestimos(self):
        return self._emprestimos

    def adicionar_emprestimo(self, carro, cliente):
        if not carro.emprestado:
            carro.emprestado = True
            self._emprestimos.append((carro, cliente))
        else:
            print(f"\nCarro {carro} já está emprestado\n")

    def devolver_carro(self, carro):
        for emprestimo in self.emprestimos:
            if emprestimo[0] == carro:
                carro.emprestado = False
                self.emprestimos.remove(emprestimo)
                print(f"\nCarro {carro} devolvido com sucesso\n")
                return
        print(f"Carro {carro} não está emprestado")

    def imprimir_emprestimos(self):
        if not self.emprestimos:
            print("Nenhum carro emprestado")
        else:
            for carro, cliente in self.emprestimos:
                print(f"Carro: {carro} - Cliente: {cliente.nome}")


class Cliente:
    def __init__(self, nome):
        self._nome = nome

    @property
    def nome(self):
        return self._nome

    @nome.setter
    def nome(self, nome):
        self._nome = nome

    def __str__(self):
        return self.nome


cliente1 = Cliente("João")
carro1 = Carro("Fusca", 1990, "ABC-1234")
cliente2 = Cliente("Maria")
carro2 = Carro("Ford-KA", 2001, "CBA-4321")

emprestimo = Emprestimo()

emprestimo.adicionar_emprestimo(carro1, cliente2)
emprestimo.adicionar_emprestimo(carro2, cliente1)
emprestimo.adicionar_emprestimo(carro1, cliente1)

emprestimo.imprimir_emprestimos()

emprestimo.devolver_carro(carro1)
emprestimo.imprimir_emprestimos()