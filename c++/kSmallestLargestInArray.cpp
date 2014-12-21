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
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <bitset>
#include <stdexcept>
#include <cassert>

typedef unsigned int uint;
typedef std::vector<int> vi;
using namespace std;

/*** Problem statement:
 * find k largest/smallest elements of a array
 *
 * Approach: this is best handled using min/max heap.
 *  - create a k items min/max heap
 *  - loop i = [k..N)
 *      if a[i] < minheap [ > maxheap]
 *          pop_min/max
 *          push (a[i]
 *  the heap should have the k smallest.argest elements
 */

void kSmallest (vi &v, int k, vi& res)
{
    if (k<=0 || k>=v.size() || v.empty() ) return; 
    priority_queue<int> q(v.begin(), v.begin() + k, std::less<int>());

    for ( auto i=k; i<v.size(); ++i ) {
        if ( q.top() > v[i] ) {
            q.pop();
            q.push(v[i]);
        }
    }
    
    while ( q.empty() !=0 ) {
    	int elem = q.top();
    	q.pop();
        res.push_back(elem);
    }
}

void kLargest (vi &v, int k, vi& res)
{
    if (k<=0 || k>=v.size() || v.empty() ) return; 

    vi heap(v.begin(), v.begin() + k);

    make_heap( heap.begin(), heap.end(), std::less<int>() );

    for ( auto it=v.begin()+k; it!=v.end(); ++it ) {
        if ( heap[0]> *it ) {
            heap.pop_heap();
            heap.push_heap(v[i]);
        }
    }
    res = heap;
    copy(res.begin(), res.end(), ostream_iterator<int>(cout," ");
}

void test_kElements()
{
    vi v(20), res;
    iota(v.begin(), v.end(), 1);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout," ");
    kLargest (v, 3, res);

}

int main()
{
	test_kElements();
	
}