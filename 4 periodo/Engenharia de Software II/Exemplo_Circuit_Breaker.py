import time
import random

class CircuitBreaker:
    def __init__(self, limite_falhas=2, tempo_recuperacao=5):
        self.limite_falhas = limite_falhas  # Quantidade de falhas consecutivas para abrir o disjuntor
        self.tempo_recuperacao = tempo_recuperacao  # Tempo de espera antes de tentar novamente
        self.contador_falhas = 0
        self.ultima_falha = None
        self.estado = "FECHADO"  # Estados possíveis: FECHADO, ABERTO, SEMI_ABERTO

    def executar(self, funcao):
        tempo_atual = time.time()

        if self.estado == "ABERTO":
            if tempo_atual - self.ultima_falha >= self.tempo_recuperacao:
                self.estado = "SEMI_ABERTO"
                print("Estado = SEMI_ABERTO: testando o serviço...")
            else:
                raise Exception("Disjuntor ABERTO: chamada bloqueada")

        try:
            resultado = funcao()
            self._restaurar()
            return resultado
        except Exception as erro:
            self.contador_falhas += 1
            print(f"Falha detectada: {erro}")

            if self.estado == "SEMI_ABERTO" or self.contador_falhas >= self.limite_falhas:
                self._abrir()
            raise

    def _abrir(self):
        self.estado = "ABERTO"
        self.ultima_falha = time.time()
        print(f"Disjuntor ABERTO: bloqueando chamadas por {self.tempo_recuperacao} segundos")

    def _restaurar(self):
        self.contador_falhas = 0
        self.estado = "FECHADO"
        print("Disjuntor FECHADO: chamadas normalizadas")

# Simulação de um serviço instável
def servico_externo():
    if random.random() < 0.5:  # 50% de chance de falha
        raise Exception("Erro no serviço externo!")
    return "Resposta OK"

# Testando o CircuitBreaker
circuit_breaker = CircuitBreaker(limite_falhas=2, tempo_recuperacao=5)

for i in range(10):
    print(f"\nChamada {i + 1}")
    try:
        resultado = circuit_breaker.executar(servico_externo)
        print(f"Resultado: {resultado}")
    except Exception as erro:
        print(f"Erro: {erro}")
    time.sleep(2)