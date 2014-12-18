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

/*
 * Given a String with length n, e.g. "abc" (n=3), output all the 
 * strings with length k (k<n) that are consisted from elements in 
 * input string. e.g. the answer for k=2 and "abc" are 
 *    aa, bb,cc,ab,ba,ac,ca,bc,cb.
 */
//void perm (string &str, uint n, uint k, uint maxk, vector<char>& res)
void perm (string &str, uint start, uint k)
{
    if (k==str.size()-1) {
        copy(str.begin(), str.end(), ostream_iterator<char>(cout, " "));
        cout << endl;
    } else {
        for (uint i=start; i<str.size(); ++i) {
            swap (str[i], str[k]);
            perm (str, start+1, k+1);
            swap (str[i], str[k]);
        }
    }
}

void comb (string &str, uint start, uint k, uint maxk, vector<char>& res)
{
#if DEBUG_    
	static int cnt;
#endif    
    if (k==maxk) {
#if DEBUG_    
    	cout<<"iter " << cnt++ << " - ";
#endif    
        copy(res.begin(), res.end(), ostream_iterator<char>(cout, " "));
        cout<< endl;
        return;
    } else {
        for (uint i=start; i<str.size(); ++i) {
            res[k] = str[i];
            comb (str, start, k+1, maxk, res);
            
        }
    }
}

void stringPermute (string & str, uint k)
{
    if (str.empty()) return;

    perm (str, 0, 0);
}

void stringCombination (string & str, uint k)
{
    if (str.empty()) return;

	vector<char> res(k,'\0');

    comb (str, 0, 0, k, res);

}

void test_stringPermute ()
{
    string s{"abcde"};
    int k=2;
    stringPermute(s,k);
}


