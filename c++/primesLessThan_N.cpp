/***
 * The Sieve of Eratosthenes
 *
 * One of the easiest yet efficient methods to generate a list of 
 * prime numbers if the Sieve of Eratosthenes (link to Wikipedia).
 *
 * Create a list with all positive integers (starting from 2 as 1 i
 *  is not considered prime).
 * Start at the first valid number (at this point all are valid) and 
 *  eliminate all its multiples from the list. So start with 2, and 
 *  eliminate 4, 6, 8, 10, 12 and so on.
 * Once all the multiples are eliminated advance to the next valid 
 *  number (one that has not been eliminated) and repeat the process, 
 *  until there are no more valid numbers to advance to.
 * */
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <memory>
#include <cstdlib>
#include <vector>
#include <new>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <bitset>
#include <stdexcept>
#include <cassert>
#include <climits>

using namespace std;

bool isPrime (long N)
{
	if (N==2 || N==3) return true;
	if (N%2==0) return false;
	
    for (long i=3; i<N/2; i+=2) {
        if ( N%i == 0) return false;
    }
    return true;
}

long primesLessThan (long N)
{
    if (N<2) return 0;

    long n = 2, cnt = 0;
    while (n<=N) {
        if (isPrime(n)) {
            cout<<n<<" ";
            ++cnt;
        }
    }
    return cnt;
}

template<typename T> T SieveOfEratosthenes( T N )
{

    if ( N<=1 ) return 0;

    vector<bool> primes(N,true);
    unsigned long cnt = 0;

    primes[0] = primes[1] = false;
    for (unsigned i=2; i*i<N; ++i) {
        if (primes[i]) {
            for (int j=i*i; j<N; j+=i)
                primes[j] = false;
        }
    }

    for (int x=0; x<N;++x) {
        if (primes[x]) {
            ++cnt;
            //cout<<x<<" ";
        }
    }
    return cnt;
}

void test_Primes()
{
	unsigned long long N = 10000000;
    cout<<"\nThere are : " <<SieveOfEratosthenes(N) << "primes less than " << N << endl;

}
