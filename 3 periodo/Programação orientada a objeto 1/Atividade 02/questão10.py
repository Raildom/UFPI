lista = []
tamanho = 2

def media(lista):
    soma = 0

    for i in lista:
        soma += i
    return soma / tamanho

def mediana(lista):
    if tamanho % 2 == 0:
        return media(lista)
    else:
        return lista[tamanho // 2]

def variancia(lista):
    aux = []
    media_ = media(lista)

    for i in lista:
        aux.append((i - media_)**2)
    variacao = media(aux)
    return variacao

def raizQuadrada(numero):
    estimativa = numero / 2.0
    anterior = 0

    while (anterior - estimativa) < 0.001:
        anterior = estimativa
        estimativa = (estimativa + numero / estimativa) / 2.0
    return estimativa

for i in range(1, tamanho + 1):
    lista.append(i)

print(f"Media: {media(lista)}")
print(f"Mediana: {mediana(lista)}")
print(f"Variancia: {variancia(lista)}")
print(f"Desvio padrao: {raizQuadrada(variancia(lista))}")