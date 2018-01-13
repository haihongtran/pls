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
try:
    clntSock.connect(ADDR)
except:
    print 'Unable to connect to remote server.'
    sys.exit()
print 'Connected to remote server. Let\'s start chatting!'
print 'TIPS: Enter \'exit()\' to exit\n'
prompt()

# List of streams to keep track of
streamList = []
streamList.append(clntSock)
streamList.append(sys.stdin)

while True:
    readableStream, writableStream, errorStream = select.select(streamList, [], [])
    for stream in readableStream:
        # Message received from remote server
        if stream == clntSock:
            data = clntSock.recv(BUFSIZ)
            if not data:
                print '\nConnection lost. Server is shut down.'
                sys.exit()
            else:
                sys.stdout.write('\r' + data)
                prompt()
        # User enters message
        else:
            msg = sys.stdin.readline()
            clntSock.send(msg)
            # Exit code
            if msg == "exit()\n":
                print 'Exiting...'
                clntSock.close()
                sys.exit()
            prompt()

clntSock.close()
