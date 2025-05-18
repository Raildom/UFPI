lista =  [1, 'a', 2.5, True]

def imprimeLista(lista):
    for i in lista:
        if isinstance(i, list):
            imprimeLista(i)
        else:
            print(i)
        
imprimeLista(lista)