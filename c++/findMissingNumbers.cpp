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
typedef vector<int> vi;
typedef vector<vector<int>> Matrix;
//typedef pair<uint,uint> puii;
struct puii
{
    uint one, two;
    puii():one(0),two(0){};
    puii(uint x, uint y):one(x),two(y){}
    friend std::ostream& operator<<(ostream&, const puii&);
};

ostream& operator<<(ostream& os, const puii& p)
{
    os <<"(one,two) = (" << p.one << "," << p.two << ")" << endl;
    return os;
}


/**
 * Given an unsorted non-repeating array of N integers.  The integers 
 * are in [1..N].  One element is removed from the array.
 * Find the missing number.
 * Complexity: O(n) time, O(1) space
 */
template<> uint findMissingNumber_unorderedArray<uint> (const vector<uint>& v)
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
template<> uint findMissingNumber_orderedArray<uint> (const vector<uint>& v,
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

template<> uint findMissingNumber_orderedArray<uint> (const vector<uint>& v)
{
    if (v.empty()) return 0;
    return findMissingNumber_orderedArray<uint> (v,0,v.size());
}

template<> puii findTwoMissingNumber_orderedArray<uint> 
    (const vector<uint>& v, uint lo, uint hi, uint k)
{
    uint mid = (lo+hi)/2;
    
    if (v[hi] - v[lo] == 3) {
        puii p{v[lo],v[hi]};
        return p;
    } else if (v[mid] - mid == 2) {
        uint one = findMissingNumber_orderedArray<uint> (v,lo,mid);
        uint two = findMissingNumber_orderedArray<uint> (v,mid+1,hi);
        puii p{one,two};
        return p;
    } else if (mid==v[mid]-1) { // both numbers are in the high side
        lo = mid;
        return findTwoMissingNumber_orderedArray<uint> (v,lo,hi,k);
    } else if (v[mid] - mid >= 3) { // both are in the low side
        hi = mid;
        return findTwoMissingNumber_orderedArray<uint> (v,lo,hi,k);
    }
}

template<> puii findTwoMissingNumber_orderedArray<uint> (const vector<uint>& v)
{
    if (v.empty()) return 0;
    return findTwoMissingNumber_orderedArray<uint> (v,0,v.size(),2);
}

void test_findMissingNumbers ()
{
    vi v1{1,2,3,4,5,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    cout <<"missing #: " <<findMissingNumber_orderedArray<uint> (v1);

    vi v2{1,2,3,4,5,7,8,9,10,11,12,13,14,16,17,18,19,20};
    vi v3{1,2,3,4,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vi v4{1,3,4,5,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    cout<<"missing pair " << findTwoMissingNumber_orderedArray<uint> (v2);
    cout<<"missing pair " << findTwoMissingNumber_orderedArray<uint> (v3);
    cout<<"missing pair " << findTwoMissingNumber_orderedArray<uint> (v4);
}


