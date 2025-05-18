class Pessoa:
    def __init__(self, nome, idade):
        self._nome = nome
        self._idade = idade

#Está  acesando os atributos privados "_nome" e "_idade" da classe Pessoa sem usar os métodos get e set
    def exibi_dados(self):
        print(f"Nome: {self._nome}")
        print(f"Idade: {self._idade}")
        
class Estudante(Pessoa):
    def __init__(self, nome, idade, curso):
        super().__init__(nome, idade) 
        self._curso = curso
    
    def exibi_dados(self):
        print(f"Nome do estudante: {self.nome}")
        print(f"Idade do estudante: {self.idade}")
        #Está chamando diretamente "nome" e "idade" da classe Pessoa, sem usar os métodos get e set.
        #A forma utilizada no código está correta, porém apenas se o get e set fossem utilizados na classe Pessoa
        print(f"Curso: {self.curso}") 
        #Está chamando o atributo "curso" da classe Estudante, porém não foi criado o método get e set para ele.
    
    
pessoa1 = Pessoa("João", 25)
pessoa1.exibi_dados()   

estudante1 = Estudante("Maria", 20, "Engenharia")
estudante1.exibi_dados()