#!/usr/bin/python

from socket import *
from time import ctime

HOST = raw_input('Enter host address: ')
if not HOST:
    HOST = ''   # Any available addresses
portInput = raw_input('Enter port number: ')
if not portInput:
    PORT = 8888
else:
    PORT = int(portInput)
BUFSIZ = 4096
ADDR = (HOST, PORT)

tcpSerSock = socket(AF_INET, SOCK_STREAM)
tcpSerSock.bind(ADDR)
tcpSerSock.listen(2)

while True:
    print 'waiting for connection...'
    tcpCliSock, addr = tcpSerSock.accept()
    print '...connected from: ', addr

    while True:
        data = tcpCliSock.recv(BUFSIZ)
        if not data:
            break
        tcpCliSock.send('[%s] %s' % (
            ctime(), data))

    tcpCliSock.close()
tcpSerSock.close()
