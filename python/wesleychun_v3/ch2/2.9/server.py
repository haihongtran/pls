#!/usr/bin/python

from socket import *
import select, sys

HOST = ''   # Any available addresses
PORT = 5000
ADDR = (HOST, PORT)
BUFSIZ = 4096

def broadcastMessage(sock, msg):
    for socket in socketList:
        # Do not send the msg to server socket and the client who has sent the msg to server
        if socket != servSock and socket != sock:
            try:
                socket.send(msg)
            except:
                # This client left but the corresponding socket is not removed yet
                socket.close()
                socketList.remove(socket)

servSock = socket(AF_INET, SOCK_STREAM)
servSock.bind(ADDR)
servSock.listen(5)

# List of sockets to keep track of
socketList = []
socketList.append(servSock)
print 'Waiting for connections...'

while True:
    readableStream, writableStream, errorStream = select.select(socketList, [], [])
    for sock in readableStream:
        if sock == servSock:
            clntSock, clntAddr = sock.accept()
            socketList.append(clntSock)
            msg = '%s:%d' % clntAddr + " has connected."
            print msg
            broadcastMessage(clntSock, msg + '\n')
        else:
            data = sock.recv(BUFSIZ)
            # If data is exit code
            if data == "exit()\n":
                msg = str(sock.getpeername()) + ' has left.'
                print msg
                broadcastMessage(sock, msg + '\n')
                socketList.remove(sock)
                sock.close()
            elif str.strip(data):
                msg = '<%s:%d> ' % sock.getpeername() + data
                broadcastMessage(sock, msg)

servSock.close()
