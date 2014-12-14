/***Find the k-th Smallest Element in the Union of Two Sorted Arrays

Given two sorted arrays A, B of size m and n respectively. Find the 
k-th smallest element in the union of A and B. You can assume that 
there are no duplicate elements.

The trivial way, O(m+n):
Merge both arrays and the k-th smallest element could be accessed 
directly. Merging would require extra space of O(m+n). The linear 
run time is pretty good, but could we improve it even further?

A better way, O(k):
There is an improvement from the above method, thanks to readers
who suggested this. (See comments below by Martin for an implementation). 
Using two pointers, you can traverse both arrays without actually 
merging them, thus without the extra space. Both pointers are 
initialized to point to head of A and B respectively, and the 
pointer that has the larger smaller (thanks to a reader for this 
correction) of the two is incremented one step. The k-th smallest 
is obtained by traversing a total of k steps. This algorithm is very 
similar to finding intersection of two sorted arrays.
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
typedef vector<int> vi;
using namespace std;


///////////////////////////////////////////////////////////////////////
template<typename T> 
T kthSmallest (const vector<T> &v1, const vector<T>& v2, int k)
{
    T elem;
    int i=0, j=0;

    //static_assert (k >= v1.size() + v2.size());
    while (k>0 && i<v1.size() && j<v2.size()) {
        if (v1[i] < v2[j]) {
            elem = v1[i];
            ++i;
        } else if (v1[i] > v2[j]) {
            elem = v2[j];
            ++j;
        } else {
            elem = v1[i];
            ++i; 
            ++j; 
        }
        --k;
    }
    while (k>0 && i<v1.size()) {
        elem = v1[i++];
        --k;
    }
    while (k>0 && j<v2.size()) {
        elem = v2[j++];
        --k;
    }

    return elem;
}


/*****************************************************************************/
int main()
{
    vi v1{3,6,9,14,33,67,109,345};
    vi v2{2,6,10,11,43,58,77};
    int k = 7;

    cout<<kthSmallest(v1,v2,k);
    cout<<endl;
}
