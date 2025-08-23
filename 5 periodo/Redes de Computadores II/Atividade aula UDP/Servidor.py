import socket
import math

UDP_IP_ADDRESS = "127.0.0.1"
UDP_PORT_NO = 6789

serverSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serverSock.bind((UDP_IP_ADDRESS, UDP_PORT_NO))

print("Servidor UDP aguardando...")

while True:
    msg, addr = serverSock.recvfrom(1024)
    n = int(msg.decode())
    resultado = math.factorial(n)
    serverSock.sendto(str(resultado).encode(), addr)