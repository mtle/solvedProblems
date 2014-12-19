#!/usr/bin/python -tt
import sys

CHAR_BIT = 8
def swapBits(x,lo,hi):
    int('{:08b}'.format(x)[::-1], 2)
    mask = ((x>>lo)&1) ^ ((x>>hi)&1)
    if mask==1: x = x ^ ((mask<<lo)|(mask<<hi))
    return x
	
def reverseBits(x,j):
    int('{:08b}'.format(x)[::-1], 2)
    i = 0
    cnt = j / 2
    print(j,cnt)
    '''while i<cnt:
        x = swapBits(x,i,j)
        ++i
        --j '''
    return x

def main():
    '''for i in range(2,10): '''
    x = 0xf
    int('{:08b}'.format(x)[::-1], 2)
    j = x.bit_length()
    print( format(x,'08x'), j )
    print( format(x,'08x'), format(reverseBits(x,j),'08x') )
        #print( fib (int i) )

if __name__ == '__main__':
    main()



