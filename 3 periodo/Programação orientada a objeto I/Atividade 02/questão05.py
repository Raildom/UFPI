import random

while True:
    x = random.randint(0, 100)

    for i in range(0, 10):
        print(f"Tentativa {i + 1}: ")
        num = int(input("Digite um numero: "))
        if num == x:
            print(f"Parabens!\nVoce acertou.\nO numero sorteado foi {x}")
            break
    opcao = int(input("\n[1] - CONTINUAR\n[0] - SAIR\n: "))
    if opcao == 0:
        break
    else:
        continue