from socket import socket, AF_INET, SOCK_DGRAM
s = socket(AF_INET, SOCK_DGRAM)
s.bind (('127.0.0.1',10000))
while True:
    data, addr = s.recvfrom(1024)
    print ("Connection from", addr, "Data:",data)
    s.sendto(data.upper(), addr)