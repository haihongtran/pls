#!/usr/bin/python

from socket import *
from time import ctime
import os

HOST = ''   # Any available addresses
PORT = 8888
BUFSIZ = 4096
ADDR = (HOST, PORT)

tcpSerSock = socket(AF_INET, SOCK_STREAM)
tcpSerSock.bind(ADDR)
tcpSerSock.listen(5)


while True:
    counter = 0
    print 'waiting for connection...'
    tcpCliSock, addr = tcpSerSock.accept()
    print '...connected from: ', addr

    while True:
        counter += 1
        data = tcpCliSock.recv(BUFSIZ)
        if not data:
            break
        elif data == 'date':
            returnData = '[%d] %s' % (counter, ctime())
        elif data == 'os':
            returnData = '[%d] %s' % (counter, os.name)
        elif data == 'ls':
            returnData = '[%d] %s' % (counter, os.curdir)
        else:
            returnData = '[%d][%s] %s' % (counter, ctime(), data)
        tcpCliSock.send(returnData)

    tcpCliSock.close()
tcpSerSock.close()
