preco = 5.0
quantidade = 120
lucro_maximo = 0.0
preco_maximo = 0.0
quantidade_maxima = 0

while preco >= 1.0:
    lucro = preco * quantidade - 200
    print(f"| R$ {preco:.2f} | {quantidade} | R$ {lucro:.2f} |")
    if lucro > lucro_maximo:
        lucro_maximo = lucro
        preco_maximo = preco
        quantidade_maxima = quantidade
    preco -= 0.5
    quantidade += 26

print(f"\nLucro máximo: R$ {lucro_maximo:.2f}")
print(f"Preço do ingresso: R$ {preco_maximo:.2f}")
print(f"Quantidade vendida: {quantidade_maxima}")