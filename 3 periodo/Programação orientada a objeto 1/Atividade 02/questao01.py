palavra = input("Digite uma palavra qualquer: ")

def tamString(s):
    count = 0
    for i in s:
        count += 1
    return count

s = tamString(palavra)
print(s)