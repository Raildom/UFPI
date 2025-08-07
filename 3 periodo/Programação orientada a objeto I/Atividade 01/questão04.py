def primo(n):
    if n <= 1:
        return False
    elif n == 2:
        return True
    elif n % 2 == False:
        return False
    for i in range(3, n // 2 + 1, 2):
        if n % i == 0:
            return False
    return True

def intervalo(num1, num2):
    encontrou = False
    for i in range(num1, num2 + 1):
        if primo(i):
            print(f"{i}")
            encontrou = True
    if not encontrou:
        print("Não existe nenhum número primo dentro desse intervalo")

while True:
    try:
        num1 = int(input("Digite um número inteiro: "))
        num2 = int(input("Digite outro número inteiro: "))
        break
    except:
        continue
intervalo(num1, num2)