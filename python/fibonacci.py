#!/usr/bin/python -tt

memo = {}

def main():
    for i in range(2,10):
        print( i, fib(i) )
        #print( fib (int i) )


def fib(n):
    if n<=2:
        return 1
    if n in memo:
        return memo.get(n)

    memo[n] = fib( n-1 ) + fib( n-2 )
    return memo[n]

if __name__ == '__main__':
    main()
