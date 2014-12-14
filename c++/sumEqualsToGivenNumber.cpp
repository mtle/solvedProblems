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
#include <utility>
#include <iterator>
#include <bitset>
#include <stdexcept>
#include <cassert>

typedef unsigned int uint;
using namespace std;

struct pii
{
    int first, second;
    pii():first(0),second(0){}
    pii(int n, int m):first(n),second(m){}

    friend std::ostream& operator<<(std::ostream&, const pii&);
};

std::ostream& operator<<(std::ostream& os, const pii& p)
{
    os << "(first,second) = (" << e.first;
    os << "," << e.second << ")" << endl;
    return os;
}

pii findPair_sortedArray (vector<int>& v, int sum)
{
    pii p();
    if (v.empty()) return p;
    int i, j;
    i=0;
    j=v.size()-1;
    while (i<j) {
        int s = v[i] + v[j];
        if (s < sum)  // move right
            ++i;
        else if (s > sum) // move left
            --j;
        else {
            p.first = v[i];
            p.second = v[j];
            break;
        }
    } // end while loop
    
    return p;
}

int test_sum()
{
    vector<int>v{5,9,70,43,2,6,11,31,8,18};
    sort(v.begin(),v.end());
    pii p = findPair_sortedArray(v);

    cout<<p;
}


