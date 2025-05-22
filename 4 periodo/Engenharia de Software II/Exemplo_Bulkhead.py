import time
import random
from concurrent.futures import ThreadPoolExecutor

class Bulkhead:
    def __init__(self, maximo_trabalhadores=2):
        self.maximo_trabalhadores = maximo_trabalhadores
        self.executores = {}  # Dicionário para piscinas de threads por serviço

    def registrar_servico(self, nome_servico):
        """Registra um serviço com uma piscina de threads limitada."""
        self.executores[nome_servico] = ThreadPoolExecutor(max_workers=self.maximo_trabalhadores)
        print(f"Serviço '{nome_servico}' registrado com {self.maximo_trabalhadores} threads.")

    def executar(self, nome_servico, funcao):
        """Executa a função no serviço especificado usando a piscina de threads."""
        if nome_servico not in self.executores:
            raise ValueError(f"Serviço '{nome_servico}' não está registrado.")
        try:
            resultado = self.executores[nome_servico].submit(funcao).result()
            print(f"Sucesso no serviço '{nome_servico}': {resultado}")
            return resultado
        except Exception as erro:
            print(f"Falha no serviço '{nome_servico}': {erro}")
            raise

# Serviços simulados
def servico_a():
    """Simula um serviço com latência e possibilidade de falha."""
    time.sleep(random.uniform(0.5, 1))  # Simula latência de 0.5 a 1 segundo
    if random.random() < 0.5:  # 50% de chance de falha
        raise Exception("Erro no serviço A!")
    return "Serviço A executado com sucesso"

def servico_b():
    """Simula um serviço com latência e possibilidade de falha."""
    time.sleep(random.uniform(0.2, 0.5))  # Simula latência de 0.2 a 0.5 segundo
    if random.random() < 0.3:  # 30% de chance de falha
        raise Exception("Erro no serviço B!")
    return "Serviço B executado com sucesso"

# Teste do padrão Bulkhead
def principal():
    bulkhead = Bulkhead(maximo_trabalhadores=2)  # 2 threads por serviço
    bulkhead.registrar_servico("servico_a")
    bulkhead.registrar_servico("servico_b")

    # Executa chamadas aos serviços
    for i in range(10):
        try:
            bulkhead.executar("servico_a", servico_a)
        except Exception:
            pass  # Erros são exibidos pelo print
        try:
            bulkhead.executar("servico_b", servico_b)
        except Exception:
            pass  # Erros são exibidos pelo print
        time.sleep(0.1)  # Pausa breve entre iterações

if __name__ == "__main__":
    principal()