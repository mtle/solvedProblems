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

using namespace std;

/**
 *  Time complexity: in O(log(n)+log(n)).
 *  How? By using a method called exponentiation by squaring.
 *
 *  The basic idea: for any a**b, if b is even we could write it as a**(b/2)**2. 
 *  If b is odd, on the other hand, we could write it as a * (a^(b-1/2))^2.
 *  */

template<typename T, typename U> T fastPower(T a, U b)
{
    if ( b==0 ) return 1;

    bool sign = false;

    if ( b<0 ) {
        sign = true;
        b = -b;
    }

    T result = 1;

    while (b) {
        if (b%2 == 0) result *= a;
        b >>= 1;
        a *= a;
    }

    return (sign) ? 1.0/result : result;
}

void test_fastPower ()
{
    long a = 10;
    long b = 3;

    fastPower(a, b);
}
