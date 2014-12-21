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
typedef vector<int> vi;
typedef vector<vector<int>> Matrix;
typedef pair<int,int> pii;
typedef pair<uint,uint> puii;

/**
 * Given a knapsack with maximum capacity W, and a set S consisting of n items
 * Each item i has some weight wi and benefit value bi(all wi, bi and W are integer values)
 * Problem: How to pack the knapsack to achieve maximum total value of packed items?
 *
 * Recursive formula for subproblems:
 *	wi: weight of item i
 *	bi: benefit of item i
 *   B[i,w] : total benefit at item i with weight w.
 *   if wi > w 
 *		B[k,w] = B[k-1,w]
 *   else // wi <= w
 *		max{B[k-1,w],B[k-1,w-wk]+bk}
 *
 *	Basecase: zero item OR zero weight return zero
 */
 
template<typename T> T knapsack (const vector<pair<T,T>>&, T, T, T);
template<typename T> T knapsack_dp (const vector<pair<T,T>>&, T);

template<> uint knapsack<uint> (const vector<puii>& S, uint item, uint w, uint W)
{
    if (item==0 || w==0) return 0;
    else if ( w==W ) {
        return 0;
    } else if ( w<S[item].second ) {
        return knapsack (S,k+1,w+S[item].second,W);
    } else {
        return max (knapsack (S,k+1,w+S[item].second,W),
                    knapsack (S,k+1,w+S[item].second,W));
    }
}

/** S.first = value
 *  S.second = weight
 */
template<> uint knapsack_dp<uint> (const vector<puii>& S, uint W)
{
    if ( W<=0 || S.empty() ) return 0;
    uint nItem = S.size();

    Matrix B(nItem+1,vi(nW+1,0));

    for (int i=1; i<=nItem; ++i) {
        for (int w=1; w<=W; ++w) {
            if (w < S[i].second) {
                B[i][w] = B[i-1][w];
            } else {
                B[i][w] = max(B[i-1][w], B[i-1][w-S[i].second] + S[i].first);
            }
        }
    }
    return B[nItem][W];
}

void test_knapsack()
{
    vector<puii> S{(10,5),(40,4),(30,6),(50,3)};
    uint W = 10;

    cout <<"ans: (4,10)=90 - knapsack = " << knapsack_dp(S, W);
    cout << endl;
}

