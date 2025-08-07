quantidade_litros = float(input("Digite a quantidade de litros: "))
tipo_combustivel = input("Digite o tipo de combustível (A-álcool, G-gasolina): ")
desconto = 0.0
preco = 0.0

if(tipo_combustivel == 'A'  or tipo_combustivel == 'a'):
    preco = quantidade_litros * 3.45
    if(quantidade_litros > 0 and quantidade_litros <= 20):
        desconto = preco * 0.03
    else:
        desconto = preco * 0.05
elif(tipo_combustivel == 'G'  or tipo_combustivel == 'g'):
    preco = quantidade_litros * 4.53
    if(quantidade_litros > 0 and quantidade_litros <= 20):
        desconto = preco * 0.04
    else:
        desconto = preco * 0.06
else:
    print("Opção incorreta!")
print(f"Valor a ser pago: {preco - desconto:.2f}")