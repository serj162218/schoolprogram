from socket import socket, AF_INET, SOCK_STREAM
s = socket(AF_INET, SOCK_STREAM)
s.bind(('127.0.0.1', 10001))
s.listen(10)
while True:
    sock, addr = s.accept()
    while True:
        data = sock.recv(500)
        if not data:
            break
        print("IP:",addr,"DATA:",data.decode())
        sock.send(data)