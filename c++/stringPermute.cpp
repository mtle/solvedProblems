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

/*
 * Given a String with length n, e.g. "abc" (n=3), output all the 
 * strings with length k (k<n) that are consisted from elements in 
 * input string. e.g. the answer for k=2 and "abc" are 
 *    aa, bb,cc,ab,ba,ac,ca,bc,cb.
 */
void perm (string &str, uint m, uint k, vector<string>& res)
{
    if (k==m) {
        res.push_back(str[m]);
        return;
    } else {
        for (int i=0; i<k; ++i) {
            swap (str[i], str[k]);
            perm (str, m+1, k, res);
            swap (str[i], str[k]);
        }
    }
}

//void stringPermute (string const & str, uint k, vector<string>& res)
void stringPermute (string const & str, uint k)
{
    if (str.empty()) return;

    // first generate dup strings, i.e aa,bb,...
    for (auto s : str) {
        string elem{};
        for (int i=0;i<k;++i) elem += x;
        res.push_back(elem);
    }

    // now generate all permutation of input string
    perm (const_cast<string>(str),0,k,res);

    copy (res.begin(),res.end(),ostream_iterator<string>(cout," "));
}

void test_stringPermute ()
{
    string s{"abc"};
    int k=2;
    stringPermute(s,k);
}


