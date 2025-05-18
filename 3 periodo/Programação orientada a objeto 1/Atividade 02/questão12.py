dicionario = {}

for i in range(2):
    lista = []
    nome = input(f"Digite o nome do {i + 1}º corredor: ")
    for j in range(3): 
        tempo = float(input(f"Digite o tempo da {j + 1}ª volta: "))
        lista.append(tempo)
    dicionario[nome] = lista

melhor_tempo = float('inf')
melhor_volta = -1
melhor_corredor = ""
campeao = ""
menor_media = float('inf')

for corredor, tempos in dicionario.items():
    media = sum(tempos) / len(tempos)
    if media < menor_media:
        menor_media = media
        campeao = corredor
    for volta, tempo in enumerate(tempos):
        if tempo < melhor_tempo:
            melhor_tempo = tempo
            melhor_volta = volta + 1
            melhor_corredor = corredor
print(f"\nO melhor tempo foi de {melhor_tempo} segundos, feito pelo corredor {melhor_corredor} na {melhor_volta}ª volta.")
print(f"O campeão foi {campeao} com uma média de {menor_media:.2f} segundos por volta.")