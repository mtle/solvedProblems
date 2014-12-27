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
//bool wordBreak (string& str, uint idx, set<string>& dict)
bool wordBreak (string& result, string const & str, const set<string>& dict)
{
    if ( dict.find(str) != dict.end() ) {
        result += str + " ";
        return true;
    }

    bool match = false;
    for (uint i=1; i<str.size(); ++i) {
        string prefix(str, 0, i);
        //auto search = dict.find(prefix);
        //if (search != dict.end()) {
        if ( dict.find(prefix) != dict.end() ) {
            result += prefix + " ";
            match = true;
        }
        string suffix(str,i,str.size()-1);
        return match & wordBreak(result, suffix, dict);
    }
    return match;
}

bool wordBreak_memoization (map<string,bool>& mem, 
                            string & result, 
                            string const & str, 
                            const set<string>& dict)
{
    if ( dict.find(str) != dict.end() || mem.find(str) != mem.end() ) {
        result += str + " ";
        return true;
    }

    bool match = false;
    for (uint i=1; i<str.size(); ++i) {
        string prefix(str, 0, i);
        if ( dict.find(prefix) != dict.end() ) {
            mem[s] = true;
            result += prefix + " ";
            match = true;
        }
        string suffix(str,i,str.size()-1);
        return match & wordBreak_memoization (mem, result, suffix, dict);
    }
    return match;
}

bool wordBreak_dp (string & result, string const & str, 
                            const set<string>& dict)
{
    if ( dict.find(str) != dict.end() ) {
        result += str + " ";
        return true;
    }

    bool match = false;
    /*
     * Create the DP table to store results of subroblems. 
     * The value dp[i] will be true if str[0..i-1] can be 
     * segmented into dictionary words, otherwise false.
     */

    vi dp(str.size()+1, -1);

    for (uint i=1; i<str.size(); ++i) {
        string prefix(str, 0, i);
        if ( dp[i] < 0 && dict.find(prefix) != dict.end() ) {
            dp[i] = i;
            result += prefix + " ";
            match = true;
        }

        if ( dp[i] > 0 ) {
            if ( i==str.size() ) return true;

            for (uint j=i+1; j<str.size(); ++j) {
                string suffix(str, i, j-i);
                if ( dp[j] < 0 && dict.find(suffix) != dict.end() ) {
                    dp[j] = j;
                    result += suffix + " ";
                    match = true;
                }
                if ( j==str.size() && dp[j] > 0 ) return true;

            }
        }

    } // end for i

    return match;
}

void test_wordBreak()
{
    vector<string> dictionary{"mobile","samsung","sam","sung","man","mango",
                              "icecream","and","go","i","like","ice","cream"};
    set<string> dict(dictionary.begin(),dictionary.end());

    string result;
    map<string,bool> mem;
    //for (string x : dictionary) dict.insert(x);

    wordBreak(result, "ilikesamsung", dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak(result, "iiiiiiii", dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak(result, "", dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak(result, "ilikelikeimangoiii", dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak(result, "samsungandmango", dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak(result, "samsungandmangok", dict)? cout <<"Yes\n": cout << "No\n";

}



