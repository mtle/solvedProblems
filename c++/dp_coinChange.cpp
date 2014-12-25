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
 * Given a number A and coins of values V = {V1,V2,V3, V4}.
 * Find number of ways change can be made for A using these coins.
 * We have infinite supply of these coins.
 * For example,
 * A = 4, V = {1,2,3}, there are four solutions: 
 *      {1,1,1,1},{1,1,2},{2,2},{1,3}
 */
 

/**
 * Let C[p] be the minimum number of coins needed to make change for
 * p cents.
 *
 * Let x be the value of the first coin used in the optimal solution.
 * Then C[p] = 1 + C[p - x] .
 * We will try all possible x and take the minimum.
 *
 * C[p] =  min{C[p-di] + 1} for all i, di<p  if p > 0
 *         0 if p = 0
 *
 * base case: 
 *      amount A = 0 - return 0
 *  else
 *      return min{coinChange(V, A-V[0]), coinChange(V,A-V[1], ... )
 */ 
uint coinChange<uint> (const vi& V, uint A)
{
    if (A<0) return INT_MAX;
    if (A==0) return 0;
    else {
        vi C(V.size());
        for (uint i=0; i<V.size(); ++i) C[i] = coinChange (V,A - V[i]);
        sort (C.begin(), C.end());
        return 1 + C[0];
    }
}

uint coinChange<uint> (const vi& d, uint A, vi& C, vi& S)
{
    if ( d.empty() || A<=0) return 0;
    // C : vector of number of coins
    // S : vector of coins [values] used
    for (int p=1; p<=A; ++p) {
        C[p] = INT_MAX;

        for (uint v=0; v<d.size(); ++v) {
            if (p >= static_cast<int>(d[v])) {
                if (C[p] > 1 + C[p-d[v]]) {
                    C[p] = 1 + C[p-d[v]];
                    S[p] = v;
                }
            }
        }
    }
    return C[A];
}

void test_coinChange()
{
    vi V{1,5,10,25};
    uint A = 77;

    cout <<"Number of coin for " << A <<" cent = " << coinChange(V, A);
    cout << endl;

    vi C(A+1), S(A+1);

    cout <<"Number of coin for " << A <<" cent [dp] = " << coinChange_dp(V, A, C, S);
    cout << endl;

    copy (S.begin(), S.end(), ostream_iterator(cout, " "));
    cout << endl;
}

