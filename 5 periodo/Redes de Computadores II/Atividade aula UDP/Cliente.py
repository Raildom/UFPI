import socket

UDP_IP_ADDRESS = "127.0.0.1"
UDP_PORT_NO = 6789

n = input("Digite um número: ")

clienteSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
clienteSock.sendto(n.encode(), (UDP_IP_ADDRESS, UDP_PORT_NO))

resp, _ = clienteSock.recvfrom(1024)
print("Fatorial:", resp.decode())