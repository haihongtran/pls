#!/usr/bin/python

from socket import *
import select, sys

HOST = ''   # Any available addresses
PORT = 5000
ADDR = (HOST, PORT)
BUFSIZ = 4096

def prompt():
    sys.stdout.write('<YOU> ')
    sys.stdout.flush()

servSock = socket(AF_INET, SOCK_STREAM)
servSock.bind(ADDR)
servSock.listen(5)

while True:
    print 'Waiting for connection...'
    clntSock, clntAddr = servSock.accept()
    print '... connected with', clntAddr
    prompt()

    while True:
        connectionLost = False
        streamList = [clntSock, sys.stdin]
        readableStream, writableStream, errorStream = select.select(streamList, [], [])
        for stream in readableStream:
            if stream == clntSock:
                data = clntSock.recv(BUFSIZ)
                if not data:
                    print '\rClient has left.'
                    connectionLost = True
                    break
                sys.stdout.write('\r<CLNT> ' + data)
                prompt()
            else:
                msg = sys.stdin.readline()
                clntSock.send(msg)
                prompt()
        if connectionLost:
            break

    clntSock.close()
servSock.close()
