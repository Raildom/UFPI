import socket
import math

HOST = "0.0.0.0"
PORT = 6789

servidorSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
servidorSock.bind((HOST, PORT))
servidorSock.listen(1)

print(f"Servidor TCP escutando em {HOST}:{PORT}")

while True:
    conn, addr = servidorSock.accept()
    print("Conexão de", addr)

    msg = conn.recv(1024).decode()
    n = int(msg)
    resultado = math.factorial(n)

    conn.sendall(str(resultado).encode())
    conn.close()
