#!/usr/bin/env python

"This is a test module"

import sys
import os

debug = True

class FooClass (object):
    "Foo class"
    printStr = "OK! String is printed."
    pass

def test():
    "Test function"
    foo = FooClass()

    if debug:
        print "test() is ran"

if __name__ == '__main__':
    test()
    print 'Executed directly'
elif __name__ == 'testModule':
    test()
    print 'Imported from another module'

