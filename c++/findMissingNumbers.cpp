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

/*
 * Two numbers are missing from the first hundred numbers. They are 
 * NOT sorted. How to find them? You can't sort and can't iterate one 
 * by one has to be less than O(N)? Can't use stack , set or any 
 * collection interface or in fact any other data structure or array!
 *
 * ALGO:
 * Suppose the maximum element of the array a[] is B i.e. suppose 
 * a[]={1,2,4} and here 3 and 5 are not present in a[] so max element is B=5
 *
 * xor all the elements of the array a to X
 * xor all the elements from 1 to B to x
 * find the left most bit set of x by x = x &(~(x-1));
 * Now if a[i] ^ x == x than xor a[i] to p else xor with q
 * Now for all k from 1 to B if k ^ x == x than xor with p else xor with q
 * Now print p and q
 */
template<> puii findTwoMissingNumber_UnorderedArray<uint> (const vector<uint>& v)
{
    if (v.empty()) return 0;
    puii missing(0,0);
    uint xor_all = 0;
    uint xor_miss = 0;

    for (uint i=0; i<v.size(); ++i) {
        xor_all ^= i;
        xor_miss ^= v[i];
    }

    // find the least significant bit set in xor_miss
    uint bit_diff = ~(xor_miss - 1) & xor_miss;

    // group the numbers based on bit_diff, i.e. one group has the bit set
    // the other has it cleared
    for (uint i=0; i<v.size(); ++i) {
        if (v[i] ^ bit_diff) missing.one ^= v[i];
        else missing.two ^= v[i];

    // compare and seperate the two numbers
    for (uint i=0; i<v.size(); ++i) {
        if (i ^ bit_diff == bit_diff) missing.one ^= i;
        else missing.two ^= i;


    return missing;
}


/*****************************************************************************/
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


