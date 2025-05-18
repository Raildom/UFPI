quantidade = float(input("Digite quanto você ganha por hora: "))
horas = float(input("Digite quantas horas você trabalha por mês: "))
salario = quantidade * horas
IR = salario * 0.11
INSS = salario * 0.08
sindicato = salario * 0.05
liquido = salario - IR - INSS - sindicato
print("Salário Bruto: R$", salario)
print("IR: R$", IR)
print("INSS: R$", INSS)
print("Sindicato: R$", sindicato)
print("Salário Líquido: R$", liquido)
