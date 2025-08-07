n = int(input("Digite um numero: "))
ant =  n
estimativa = 1

while estimativa != ant:
    ant = estimativa
    estimativa = (estimativa + (n/estimativa))/2
    
print(estimativa)

while True:
    num = int(input("Digite um numero: "))
    primo = [x for x in range(1, num + 1) if num % x == 0]
    
    if(len(primo) > 2):
        print("Não é primo")
    elif len(primo) <= 2 and len(primo) > 0 and len(primo) != 1:
        print("É primo")
    else:
        print("Não é primo")
        