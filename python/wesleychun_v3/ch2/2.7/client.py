#!/usr/bin/python

from socket import *

HOST = 'localhost'
PORT = 8888
ADDR = (HOST, PORT)
BUFSIZ = 4096

clntSock = socket(AF_INET, SOCK_STREAM)
clntSock.connect(ADDR)

while True:
    data = raw_input('<YOU> ')
    if not data:
        break
    clntSock.send(data)
    data = clntSock.recv(BUFSIZ)
    if not data:
        break
    print '<SERV> ' + data

clntSock.close()
