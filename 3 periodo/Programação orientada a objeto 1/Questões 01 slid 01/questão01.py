lado1 = float(input("Digite o primeiro lado do triângulo: "))
lado2 = float(input("Digite o segundo lado do triângulo: "))
lado3 = float(input("Digite o terceiro lado do triângulo: "))

if lado1 >= (lado2 + lado3) or lado2 >= (lado1 + lado3) or lado3 >= (lado1 + lado2):
    print("Não é possível formar um triângulo com esses valores.")
elif(lado1 == lado2 == lado3):
    print("Triângulo equilátero.")
elif(lado1 == lado2) or (lado1 == lado3) or (lado2 == lado3):
    print("Triângulo isósceles.")
else:
    print("Triângulo escaleno.")