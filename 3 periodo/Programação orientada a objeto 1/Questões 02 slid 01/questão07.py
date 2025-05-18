while(True):
    fatorial = 1
    num = int(input("Digite um número: "))
    if(num < 0):
        break
    while(num != 0):
        fatorial *= num
        num -= 1
    print(f"Fatorial: {fatorial}")