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
using namespace std;

template<typename T> uint rmDup (vector<T>& v)
{
    if ( v.empty() ) return 0;

    uint sz = v.size();
    unordered_set<T> S;

    if (size_t i=0; i<v.size(); ++i) {
    }

}

/** this routine will remove all duplicate in vector
 * using set.  It is unstable because the order of
 * elements * in array may not be the same.
 * Complexity: O(n) time, O(n) space
 */
template<typename T> uint rmDup_unstable (vector<T>& v)
{
    if ( v.empty() ) return 0;

    uint sz = v.size();
    unordered_set<T> S;

    S.insert(v.begin(),v.end());
    v.clear();
    v.insert(v.begin(),S.begin(),S.end());

    return sz-v.size();
}

void test_rmDuplicates ()
{

}