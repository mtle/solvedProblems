#!/usr/bin/python -tt

def swapBits(x,lo,hi):
    mask = ((x>>lo)&1) ^ ((x>>hi)&1)
    if mask==1: x = x ^ ((mask<<lo)|(mask<<hi))
    return x

def main():
    '''for i in range(2,10): '''
    x = 0x8
    print( x, swapBits(x,0,3) )
        #print( fib (int i) )

if __name__ == '__main__':
    main()
