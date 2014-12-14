/***
  Given a set T of characters and a string S, find the minimum window in 
  S which will contain all the characters in T in complexity O(n).

  eg,
  S = “ADOBECODEBANC”
  T = “ABC”

  Minimum window is “BANC”.
    
Hint:
Using the above example S = “ADOBECODEBANC” and T = “ABC“, we can easily 
find the first window which contains T is “ADOBEC“. Another possible 
candidate is “ADOBECODEBA“. In fact, we should skip this, because within 
it exists a sub-window “CODEBA” that is both shorter and satisfy the 
constraint. The final window to consider is “BANC“, which is also 
the minimum window.

To help illustrate this approach, I use a different example: S = “acbbaca” 
and T = “aba“. The idea is mainly based on the help of two pointers (begin 
and end position of the window) and two tables (needToFind and hasFound) 
while traversing S. needToFind stores the total count of a character in T 
and hasFound stores the total count of a character met so far. We also use 
a count variable to store the total characters in T that’s met so far (not 
counting characters where hasFound[x] exceeds needToFind[x]). When count 
equals T‘s length, we know a valid window is found.

Each time we advance the end pointer (pointing to an element x), we increment 
hasFound[x] by one. We also increment count by one if hasFound[x] is less than 
or equal to needToFind[x]. Why? When the constraint is met (that is, count 
equals to T‘s size), we immediately advance begin pointer as far right as 
possible while maintaining the constraint.

How do we check if it is maintaining the constraint? Assume that begin points 
to an element x, we check if hasFound[x] is greater than needToFind[x]. If it 
is, we can decrement hasFound[x] by one and advancing begin pointer without 
breaking the constraint. On the other hand, if it is not, we stop immediately 
as advancing begin pointer breaks the window constraint.

Finally, we check if the minimum window length is less than the current minimum. 
Update the current minimum if a new minimum is found.

Essentially, the algorithm finds the first window that satisfies the constraint,
then continue maintaining the constraint throughout.

leetcode: http://leetcode.com/2010/11/finding-minimum-window-in-s-which.html
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
#include <utility>
#include <bitset>
#include <stdexcept>
#include <cassert>

typedef unsigned int uint;
using namespace std;

template<typename U, typename V> void printMap (unordered_map<U, V>& m)
{
	cout <<"\nMap<char, int>: ";
	for ( auto x=m.begin(); x!=m.end(); ++x )  {
		cout<<"(" << x->first << "," << x->second << ")" << " ";
	}
	cout << endl;
}

pair<int,int> minWindow (const string& txt, string const &pat)
{
	unordered_map<char,int> hasChar;
	unordered_map<char,int> hasFound;
	
	for ( auto x : pat ) {
	    ++hasChar[x];
	    hasFound[x] = 0;
	}
	for ( auto x : txt ) {
	    auto search = hasFound.find(x);
	    if ( search != hasFound.end() )
	        ++hasFound[x];
	}
	
	for ( size_t i=0, j=txt.size()-1; i<=j; ++i, --j ) {
	    
	}
	printMap(hasFound);
	
	return make_pair(0,0);
}

/*****************************************************************************/
int main()
{
    string txt{"ADOBECODEBANC"};
    string pat{"ABC"};
    
    minWindow(txt, pat);
}
