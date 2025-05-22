import time
import random

class Retry:
    def __init__(self, maximo_tentativas=2, espera_entre_tentativas=0.5):
        self.maximo_tentativas = maximo_tentativas  # Quantas vezes tentar
        self.espera_entre_tentativas = espera_entre_tentativas  # Tempo de espera em segundos

    def executar(self, funcao):
        """Tenta executar a função até o número máximo de tentativas."""
        tentativa = 1
        while tentativa <= self.maximo_tentativas:
            try:
                resultado = funcao()
                print(f"Tentativa {tentativa} bem-sucedida: {resultado}")
                return resultado
            except Exception as erro:
                print(f"Tentativa {tentativa} falhou: {erro}")
                if tentativa == self.maximo_tentativas:
                    print("Limite de tentativas atingido. Não foi possível executar.")
                    raise Exception(f"Erro após {self.maximo_tentativas} tentativas: {erro}")
                time.sleep(self.espera_entre_tentativas)  # Aguarda antes de tentar novamente
                tentativa += 1

# Serviços simulados
def servico_a():
    """Simula um serviço que pode falhar."""
    time.sleep(random.uniform(0.5, 1))  # Atraso de 0.5 a 1 segundo
    if random.random() < 0.5:  # 50% de chance de falha
        raise Exception("Falha no serviço A!")
    return "Serviço A concluído com sucesso"

def servico_b():
    """Simula um serviço que pode falhar."""
    time.sleep(random.uniform(0.2, 0.5))  # Atraso de 0.2 a 0.5 segundo
    if random.random() < 0.3:  # 30% de chance de falha
        raise Exception("Falha no serviço B!")
    return "Serviço B concluído com sucesso"

# Teste do padrão Retry
def principal():
    retry = Retry(maximo_tentativas=2, espera_entre_tentativas=0.5)  # 2 tentativas, 0.5s de espera

    # Testa o serviço A
    print("\nExecutando serviço A:")
    try:
        retry.executar(servico_a)
    except Exception as erro:
        print(f"Erro final no serviço A: {erro}")

    # Testa o serviço B
    print("\nExecutando serviço B:")
    try:
        retry.executar(servico_b)
    except Exception as erro:
        print(f"Erro final no serviço B: {erro}")

if __name__ == "__main__":
    principal()