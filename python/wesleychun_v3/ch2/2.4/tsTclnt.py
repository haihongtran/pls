#!/usr/bin/python

from socket import *

HOST = raw_input('Enter host address: ')
portInput = raw_input('Enter port number: ')

if not HOST:
    HOST = 'localhost'
if not portInput:
    PORT = 8888
else:
    PORT = int(portInput)
BUFSIZ = 4096
ADDR = (HOST, PORT)

tcpCliSock = socket(AF_INET, SOCK_STREAM)
tcpCliSock.connect(ADDR)

while True:
    data = raw_input('> ')
    if not data:
        break
    tcpCliSock.send(data)
    data = tcpCliSock.recv(BUFSIZ)
    if not data:
        break
    print data

tcpCliSock.close()
