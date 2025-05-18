peso = float(input("Digite o peso do peixe: "))
if peso > 50:
    execesso = peso - 50
    multa = execesso * 4
    print(f"PESO: {peso:.2f}\nEXCESSO: {execesso:.2f}\nMULTA: {multa:.2f}")
else:
    print("Peso dentro do limite permitido!")