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

using namespace std;
typedef unsigned int uint;

class invalid_argument : public runtime_error
{
    invalid_argument(const string& e) {
        runtime_error (e){};
    }
};

template<typename T> T swapBits (T N, uint i, uint j)
{
    T Ti = (N >> i) & 1;
    T Tj = (N >> j) & 1;
  
    //if ( ((N>>i)&1) ^ ((N>>j)&1) ) 
    if ( Ti ^ Tj) )
        return N ^ ((1U<<i) | (1U<<j));
    ekse return N;
}

template<typename T> T nearestInt (T N)
{
    for (int i=0; i<CHAR_BIT * sizeof(T) - 1; ++i) {
        T ni = (N >> i) & 1;
        T nj = (N >> i+1) & 1;
        if ( ni ^ nj )
            return N ^ ((1U<<i) | (1U<<j));
            //return swapBits (N, i, i+1);
    }
    // throw an error all bits are either zeros or ones
    throw invalid_argument (
            "cannot produce nearest number: all bits are either zeros or ones");
}



