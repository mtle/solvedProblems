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
typedef unsigned int uint;
typedef vector<unsigned int> vu;
typedef vector<int> vi;
typedef pair<int,int> pii;

/**
 * Given a string and dictionary of words, we need to break given string 
 * into words which are present in dictionary.
 * For example, if given string is "dogcatruck" and dictionary is 
 * {"dog", "cat", "truck"}, then result should contain all three words.
 */

/** recursive implementation
 * The idea is to loop through the string, break it into a prefix and suffix 
 * strings at the loop index and recursively call the function
 * on the suffix.
 */
bool wordBreak (string& str, uint idx, set<string>& dict)
{
    if ( str.empty() || idx == str.size() ) return true;
    bool match = false;

    for (uint i=idx; i<str.size(); ++i) {
        string s(str, 0, i);
        auto search = dict.find(s);
        if (search != dict.end()) {
            cout << s << " ";
            match = true;
        }
        return match & wordBreak(str, i, dict);
    }
    return match;
}

void test_wordBreak()
{
    vector<string> dictionary{"mobile","samsung","sam","sung","man","mango",
        "icecream","and","go","i","like","ice","cream"};
    set<string> dict(dictionary.begin(),dictionary.end());

    //for (string x : dictionary) dict.insert(x);

    wordBreak("ilikesamsung", 0, dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii", 0, dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak("", 0, dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii", 0, dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango", 0, dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok", 0, dict)? cout <<"Yes\n": cout << "No\n";

}



