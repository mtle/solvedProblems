/**
 * Reverse words in a string
 * Approach:
 *		- reverse the whole string
 *  - then find and reverse each word
 */
 
 #include <iostream>
 #include <sstream>
 #include <iomanip>
 #include <string>
 #include <memory>
 #include <cstdlib>
 #include <vector>
 #include <new>
 //#include <unordered_set>
 //#include <unordered_map>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <utility>
 #include <bitset>
 #include <stdexcept>
 #include <cassert>
 #include <iterator>
 #include <numeric> 
 
 using namespace std;
 typedef unsigned uint;
 
 void reverse_str (string& s, uint start, uint end)
 {
     if (s.empty() || s.size()<2 || start>=end) return;
         assert (start>0 || end>0);
 		
     for (uint i=start, j=end; i<=(start+end)/2; ++i, --j) 
 				swap(s[i], s[j]);
 }
 
 void reverse_words (string& s) 
{
    reverse_str(s, 0, s.size()-1);

    copy(s.begin(),s.end(),ostream_iterator<char>(cout,""));
    cout <<endl;

    uint start, end;
    uint i=0,j=0;
    while (i<s.size()) {
        if (isalnum(s[i])) {
            start=i;
            for (j=i+1; j<s.size(); ++j) 
                if (isspace(s[j]) || ispunct(s[j])) 
                    break;
            end = j-1;

            reverse_str(s,start,end);
            i = end;
        }
        ++i;
    } 
} 

void test_reverse_words()
 {
     string s="this is a test for reversing words in a string";
 		
     reverse_words(s);
     cout<<s<<endl;
 
 }