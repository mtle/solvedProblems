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
typedef vector<int> vi;
typedef vector<vector<int>> Matrix;

using namespace std;

/**
 * Given an unsorted non-repeating array of N integers.  The integers 
 * are in [1..N].  One element is removed from the array.
 * Find the missing number.
 * Complexity: O(n) time, O(1) space
 */
//template<typename elemType>
template<> uint findMissingNumber_unsortedArray<uint> (const vector<uint>& v)
{
    uint all, one;

    all = one = 0;
    for (uint i=1;i<=v.size();++i) all ^= i;
    for (uint i=1;i<v.size();++i) one ^= i;
    return all^one;
}

/**
 * Given a sorted non-repeating array of N integers.  The integers 
 * are in [1..N].  One element is removed from the array.
 * Find the missing number.
 * Complexity: O(logn) time, O(1) space
 */
//template<typename elemType>
template<> uint findMissingNumber_sortedArray<uint> (const vector<uint>& v,
                                                     uint lo, uint hi)
{
//    if (v.empty()) return 0;

    uint lo=0, hi=v.size(), mid;
    
    while (true) {
        mid = (hi+lo)/2;

        if (v[hi] - v[lo] == 2) {
            return v[hi] - 1;
        } 
        else if (v[mid] - mid > 1)  // the missing number is in lower half
            hi = mid;
        else
            lo = mid;
    }
}


template<> uint findMissingNumber_sortedArray<uint> (const vector<uint>& v)
{
    if (v.empty()) return 0;
    return findMissingNumber_sortedArray<uint> (v,0,v.size());
}
