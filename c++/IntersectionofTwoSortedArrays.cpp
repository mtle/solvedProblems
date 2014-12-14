/*** 
Finding intersection of two sorted arrays

We can have two index, which both starts at zero. Compare the two first 
elements of A and B. If A[0] is greater than B[0], we increase index of 
B by one. If B[0] is greater than A[0], we increase index of A by one. If 
they are equal, we know an intersection has occurred, so add it to the list 
and increment index of A and B by one. Once either index reaches the end of 
A or B, we have found all the intersections of A and B.

The complexity of this approach is still O(m+n), but it does not requires 
any extra space that a hash table requires. The complexity is O(m+n) because 
in the worse case, there would be no intersection between the two arrays, and 
we need to increment first index a total of m times and increment second index 
a total of n times, which is a total of m+n times.
*/
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
#include <iterator>
#include <utility>
#include <bitset>
#include <stdexcept>
#include <cassert>

typedef unsigned int uint;
typedef vector<int> vi;

using namespace std;

template<typename T> void printVector(const vector<T> &v, int lo=0, int hi=0) const;

///////////////////////////////////////////////////////////////////////

template<typename T> void printVector(const vector<T> &v, int lo, int hi) const
{
	cout<<"\n[";
    if ( 0==lo && 0==hi ) {
   	 for ( auto x : v ) {
   		 cout<<x<<", ";
   	 }
    } else if ( lo>=0 && hi>0 ) {
   	 for (auto x=lo; x<=hi; ++x) {
   		 cout<<v.at(x) << ", ";
   	 }
    } else {
    	return;
	}
	cout<<"]"<<endl;
}

/*****************************************************************************/
template<typename T>
void intersect_usingSet (vector<T>& v1, vector<T>& v2, vector<T> & res)
{
    unordered_set<T> s;

    for (auto it=v1.begin();it!=v1.end();++it)
        s.insert(*it);

    for (auto it=v2.begin();it!=v2.end();++it) {
        auto r = s.insert(*it);
        if (!r->second) res.push_back(*it);
    }
}

template<typename T>
void intersect (vector<T>& v1, vector<T>& v2, vector<T>& res)
{
    int i=0, j=0;

    while (i<v1.size() && j<v2.size()) {
        if (v1[i] > v2[j]) ++j;
        else if (v1[i] < v2[j]) ++i;
        else res.push_back(v1[i]);

    } // end while
}
/*****************************************************************************/
int main()
{
    vi res;
    vi v1{4,6,8,2,5,11,7,32,45,104};
    vi v2{9,7,11,45,87,88,67,54,19,22,104};

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    intersect(v1,v2,res);

    copy(res.begin(),res.end(),std::ostream_iterator<int>(std::cout," "));
    cout<<endl;

}
