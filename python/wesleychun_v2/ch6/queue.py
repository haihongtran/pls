#!/usr/bin/env python

queue = []

def enqueue():
    queue.append(raw_input("Enter new string: "))

def dequeue():
    if len(queue) == 0:
        print "Queue is empty"
    else:
        print '[' + queue.pop(0) + '] is removed.'

def viewqueue():
    print queue

CMDs = {'e': enqueue, 'd': dequeue, 'v': viewqueue}

def showmenu():
    pr = '''
(E)nqueue
(D)equeue
(V)iew
(Q)uit

Enter your choice: '''

    while True:
        while True:
            try:
                choice = raw_input(pr).lower()
                # choice = raw_input(pr).strip()[0].lower()
            except (EOFError, KeyboardInterrupt, IndexError):
                choice = 'q'
            print '\nYou picked [%s]' % choice
            if choice not in 'edvq':
                print 'Invalid choice, try again.'
            else:
                break
        if choice == 'q':
            break
        CMDs[choice]()

if __name__ == '__main__':
    showmenu()