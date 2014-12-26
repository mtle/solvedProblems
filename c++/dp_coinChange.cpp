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

uint coinChange<uint> (const vi& d, uint A, vi& change)
{
    if ( d.empty() || A<=0) return 0;
    // C : vector of number of coins
    // S : vector of coins [values] used
    vi C(A+1), S(A+1);
    C[0] = 0;

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
    while (A>0) {
        change.push_back( d[S[A]] );
        A -= d[S[A]];
    }
    return C[A];
}

void test_coinChange()
{
    vi cent_denom{1,5,10,25};
    vi dollar_denom{1,5,10,20,50,100};
    uint A = 77;

    cout <<"Number of coin for " << A <<" cent = " << coinChange(V, A);
    cout << endl;

    vi C;
    double amount = 187.87;
    uint dollars = static_cast<uint>(amount);
    uint cents = static_cast<uint>((amount - dollars)*100);
    cout <<"Change for " << amount <<":" << endl;
    cout <<"--- dollar bills: " << coinChange_dp(dollar_denom, dollars, C) << " bills, they are : ";
    copy (C.begin(), C.end(), ostream_iterator(cout, " "));
    cout << endl;

    C.clear();

    cout <<"--- coin change : " << coinChange_dp(cent_denom, cents, C) << " coins, they are : ";
    copy (C.begin(), C.end(), ostream_iterator(cout, " "));
    cout << endl;

    cout << endl;
}

