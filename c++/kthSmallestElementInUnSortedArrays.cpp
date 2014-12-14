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

 unsigned int uint;
#define vi vector<int>
using namespace std;


///////////////////////////////////////////////////////////////////////
template<typename T> 
uint partition (vector<T> &v, uint lo, uint hi, T& pivot)
{
    if (lo==hi) return;

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
    return j;
}

template<typename T> 
T kthSmallest (const vector<T> &v, uint lo, uint hi, uint k)
{
    T pivot;
    uint i=0, j=0;

    partition (v,lo,hi,pivot);
    if (k==pivot) return v[k];
    else if (k>pivot)
    else

    return v[pivot];
}

template<typename T> 
T kthSmallest (const vector<T> &v, uint k)
{
    assert (k < 1 || k >= v.size());
    return kthSmallest (v, k);
}

/*****************************************************************************/
int main()
{
    vi v1{3,6,9,14,33,67,109,345};
    uint k = 7;

    cout<<kthSmallest(v1,k);
    cout<<endl;
}
