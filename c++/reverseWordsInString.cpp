/**
 * Reverse words in a string
 * Approach:
 *		- reverse the whole string
 *  - then find and reverse each word
 */
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cassert>

using namespace std;
typedef unsigned uint;
 
void reverse_str (string& s, uint start, uint end)
{
    if (s.empty() || s.size()<2 || start>=end) return;
    assert (start>0 || end>0);

    for (uint i=start, j=end; i<=(start+end)/2; ++i, --j) 
        swap(s[i], s[j]);
}
 
void reverse_str (string& s) 
{
    reverse_str(s, 0, s.size()-1);

    uint start, end;
    for (start=0; start<s.size(); ++start) {
        if (isalnum(s[start])) {
            for (end=start+1; end<s.size(); ++end) 
                if (isspace(s[end]) || ispunct(s[end])) 
                    break;

            reverse_str(s,start,end-1);
            start = end;
        }
    } 
} 

void test_reverse_words()
{
    string s="this is a test for reversing words in a string";

    reverse_str(s);
    cout<<s<<endl;

}
