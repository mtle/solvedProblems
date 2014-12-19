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
typedef unsigned long long ull;
using namespace std;

/**
 * Define the number of bits that are set to 1in an unsigned 
 * 64-bit integer x to be the weight of x. Let S denote the 
 * set of unsigned 64-bit integers whose weight is k.  
 * Suppose x E Si and k is not 0 or 64. How would you 
 * compute y E S\ {x} such that |y - x| is minimum?
 *
 * Approach: find the 1st 1-bit that is preceded by a 0-bit
 * and swap the 2 bits.
 **/

template<typename T> T swapBits (T x, uint lo, uint hi)
{
    T mask = (((x>>lo)&1) ^ ((x>>hi)&1));

    if ( mask ) x ^= ((mask<<hi) | (mask<<lo));
    return x;
}

template<typename T> uint bitCount (T x)
{
    uint count = 0;
    while (x) {
        ++count;
        x &= (x-1);
    }
    return count;
}

template<typename T> uint firstOne2ZeroPattern (T x)
{

    uint firstOne = 0;
    for (uint i=0; i<sizeof(x); ++i) {
        if ( x&1 ) {
        	if (firstOne==0 )
        		firstOne = i;
        	else {
        		if (i - firstOne == 1)
        			firstOne = i;
        		else 
            		return firstOne;;
        	}
        }
        x >>= 1;
    }
   
    return firstOne;
}

template<typename T> T nextLargerInteger (T x)
{
    uint firstBitSet = firstOne2ZeroPattern (x);
    return swapBits (x, firstBitSet, firstBitSet+1);

}



