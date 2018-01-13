#!/usr/bin/python

from socket import *
import select, sys

HOST = 'localhost'
PORT = 5000
ADDR = (HOST, PORT)
BUFSIZ = 4096

def prompt():
    sys.stdout.write('<YOU> ')
    sys.stdout.flush()

clntSock = socket(AF_INET, SOCK_STREAM)
clntSock.connect(ADDR)
prompt()

while True:
    connectionLost = False
    streamList = [clntSock, sys.stdin]
    readableStream, writableStream, errorStream = select.select(streamList, [], [])
    for stream in readableStream:
        if stream == clntSock:
            data = clntSock.recv(BUFSIZ)
            if not data:
                print '\rConnection lost.'
                connectionLost = True
                break
            sys.stdout.write('\r<SERV> ' + data)
            prompt()
        else:
            msg = sys.stdin.readline()
            clntSock.send(msg)
            prompt()
    if connectionLost:
        break

clntSock.close()
