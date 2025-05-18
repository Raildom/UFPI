def calcular_anos(X, Y):
    quant_anos = 0
    while X <= Y:
        X = X + (X * 0.03)
        Y = Y + (Y * 0.015)
        quant_anos += 1
    return quant_anos


A = int(input("Digite o valor de A: "))
B = int(input("Digite o valor de B: "))
print(f"É necessario {calcular_anos(A, B)} anos para que a população do país A ultrapasse ou iguale a população do país B")
