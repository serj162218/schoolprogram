from socket import socket, AF_INET, SOCK_STREAM
import sys
s = socket(AF_INET, SOCK_STREAM)
s.bind(('127.0.0.1',0))
addr = ('127.0.0.1',10001)
s.connect(addr)
while True:
    s.send(input("input:").encode())
    data = s.recv(500)
    print("IP:",addr,"DATA:",data.decode())
