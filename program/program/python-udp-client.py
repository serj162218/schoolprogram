from socket import socket, AF_INET, SOCK_DGRAM
s = socket(AF_INET, SOCK_DGRAM)
s.bind (('127.0.0.1',0))
server = ("127.0.0.1",10000)
s.sendto('hello'.encode(),server)
data, addr = s.recvfrom(1024)
print ("Connection from", addr, "Data:",data.decode())
s.close()