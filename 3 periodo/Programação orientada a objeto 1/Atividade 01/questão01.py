while True:
    area = 0.0
    try:
        print("\n[1] triângulo\n[2] quadrado\n[3] círculo\n[4] sair\n")
        opcao = int(input("Digite a forma escolhida: "))
        if opcao == 1:
            lado = float(input("Informe o lado: "))
            altura = float(input("Informe a altura: "))
            area = lado * altura / 2
        elif opcao == 2:
            lado = float(input("Informe o valor do lado: "))
            area = lado**2
        elif opcao == 3:
            raio = float(input("Informe o raio: "))
            area = 3.1415 * raio**2
        elif opcao == 4:
            break
        else:
            print("\nOpção inválida!\n")
    except:
        continue
    print(f"\nÁREA: {area:.2f}\n")