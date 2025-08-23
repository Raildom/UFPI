import socket

HOST = "127.0.0.1"
PORT = 6789

clienteSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clienteSock.connect((HOST, PORT))

n = input("Digite um número: ")
clienteSock.sendall(n.encode())

resp = clienteSock.recv(1024).decode()
print("Fatorial:", resp)

clienteSock.close()
