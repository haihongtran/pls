#!/usr/bin/python

from socket import *

HOST = ''   # Any available addresses
PORT = 8888
ADDR = (HOST, PORT)
BUFSIZ = 4096

servSock = socket(AF_INET, SOCK_STREAM)
servSock.bind(ADDR)
servSock.listen(5)

while True:
    print 'waiting for connectioin...'
    clntSock, clntAddr = servSock.accept()
    print '...connected with', clntAddr

    while True:
        data = clntSock.recv(BUFSIZ)
        if not data:
            break
        print '<CLNT> ' + data
        data = raw_input('<YOU> ')
        clntSock.send(data)

    clntSock.close()
servSock.close()
