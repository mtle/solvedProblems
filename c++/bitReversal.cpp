#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <memory>
#include <limits>
#include <vector>
#include <new>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <bitset>
#include <stdexcept>
#include <cassert>

typedef unsigned int uint;
typedef unsigned long long u64;
using namespace std;

/*  
 *  Write a function that takes a 64-bit integer x and returns 
 *  a 64-bit integer consisting of the bits of x in reverse order.
 *
 *  Approach:
 *      let sz = sizeof(u64) / 2
 *      loop i=0..sz, j=sz..0
 *      extract bit i and j
 *      swap the bit using xor
 **/

template<typename T> T swapBits ( T x, int lo, int hi )
{
    T mask = ((x>>lo)&1) ^ ((x>>hi)&1);

    if (mask) x ^= (mask<<hi) | (mask<<lo);
    return x;
}

template<typename T> T bitReversal ( T x )
{

    uint sz = CHAR_BIT * sizeof(x);

    for (uint i=0, j=sz-1; i<sz/2; ++i,--j) {
        x = swapBits (x, i, j);
    }

    return x;
}

void test_bitReversal()
{
    u64 x = 0xf;

    cout << hex << bitReversal(x);
}


