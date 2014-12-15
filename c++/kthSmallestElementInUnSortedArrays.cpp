/***Find the k-th Smallest Element in an unsorted array of integers 

  There are 3 ways that the kth element can be found:
    1. Sort the array and return the kth element.
        complexity O(nlogn)
    2. Quick select.  complexity O(n), worst case O(nlogn)
    3. Median of median.  O(n) worst case
*/
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <memory>
#include <iterator>
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
#include <type_traits>

typedef unsigned int uint;
#define vi vector<int>
using namespace std;


///////////////////////////////////////////////////////////////////////
template<typename T> 
uint partition (vector<T> &v, uint lo, uint hi)
{
    if (lo==hi) return lo;

    pivot = v[lo];
    uint i=lo+1, j=hi;

    while (i<j) {
        if (v[i] >= pivot && v[j] < pivot) {
            swap(v[i],v[j]);
            ++i;
            --j;
        } else if (v[i] > pivot && v[j] > pivot) {
            --j;
        } else if (v[i] < pivot && v[j] < pivot) {
            ++i;
        }
    } // end while
    swap (v[0], v[j]);
    idx = j;
    return j;
}

template<typename T> 
uint randomizedPartition (vector<T> &v, uint lo, uint hi)
{
    if (hi-lo>100) {
        uint i = rand() % (hi-lo);    
        swap(v[lo],v[lo+i]);
    }
    retutn partition (v, lo, hi);
}

template<typename T> 
T kthSmallest (const vector<T> &v, uint lo, uint hi, uint k)
{
    if (lo==hi) return v[lo];

    uint pivot = randomizedPartition (v,lo,hi);

    if (k==pivot) return v[k];
    else if (k>pivot) {
        return kthSmallest (v,pivot+1,hi,k);
    } else {
        return kthSmallest (v,lo,pivot-1,k);
    }
}

template<typename T> 
T medianOfMedians (vector<T> &v)
{
    if (5 >= v.size()) {
        sort (v.begin(),v.end());
        return v[v.size()/2];
    }
    // step 1: compute vector of medians of group of 5
    auto start = v.begin();
    auto end = std::next(v.begin(),5);
    vector<T> medians;

    for (uint i=0;i<v.size();i+=5) {
        sort(start,end);
        medians.push_back(*(start+3));
        start = end;
        end += 5;
    }

    sort(start,v.end());
    medians.push_back(*(start+3));

    // step 2: recursively call medianOfMedians
    return medianOfMedians(medians);
}

template<typename T> 
T randomizedSelect (vector<T>& v, uint lo, uint hi, uint k)
{
    if ( lo==hi ) return v[lo];

}

template<typename T> 
T kthSelect (const vector<T> &v, uint lo, uint hi, uint k)
{
    if (lo==hi) return v[lo];

    uint pivot = randomizedPartition (v,lo,hi);
    
    if (k==pivot) return v[k];
    else if (k>pivot) {
        return kthSelect (v,pivot+1,hi,k);
    } else {
        return kthSelect (v,lo,pivot-1,k);
    }
}

template<typename T> 
T kthSmallest (const vector<T> &v, uint k)
{
    assert (k < 1 || k > v.size());
    return kthSmallest (v, k-1);
}

/*****************************************************************************/
int main()
{
    vi v1{3,6,9,14,33,67,109,345};
    uint k = 7;

    cout<<kthSmallest(v1,k);
    cout<<endl;
}
