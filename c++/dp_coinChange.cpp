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
typedef vector<unsigned int> vu;
typedef vector<vector<int>> Matrix;
typedef pair<int,int> pii;
typedef pair<uint,uint> puii;

/**
 * Given a number A and coins of values d = {d1,d2,d3, d4}.
 * Find number of ways change can be made for A using these coins.
 * We have infinite supply of these coins.
 * For example,
 * A = 4, d = {1,2,3}, there are four solutions: 
 *      {1,1,1,1},{1,1,2},{2,2},{1,3}
 */
 

/**
 * Let C[p] be the minimum number of coins needed to make change for
 * p cents.
 *
 * Let x=d[i] be the value of the first coin used in the optimal solution.
 * Then C[p] = 1 + C[p - x] .
 * We will try all possible x and take the minimum.
 *
 * C[p] =  min{C[p-di] + 1} for all i, di<p  if p > 0
 *         0 if p = 0
 *
 * base case: 
 *      amount A < 0 - return large int
 *      amount A = 0 - return 0
 *  else
 *      return min{makeChange(V, A-V[0]), makeChange(V,A-V[1], ... )
 */ 
uint makeChange (const vu& d, int A)
{
    if (A<0) return 10000;
    if (A==0) return 0;
    else {
        vu C(d.size());
        for (uint i=0; i<d.size(); ++i) {
            C[i] = 1 + makeChange (d,A - d[i]);
        }
        sort (C.begin(), C.end(),std::less<int>());
        return C[0];
    }
}

uint makeChange_dp (const vu& d, uint A, vu& change)
{
    if ( d.empty() || A<=0) return 0;
    // C : vector of number of coins
    // S : vector of coins [values] used
    vu C(A+1), S(A+1);
    C[0] = 0;

    for (uint p=1; p<=A; ++p) {
        C[p] = 50000;

        for (uint v=0; v<d.size(); ++v) {
            if (p >= static_cast<int>(d[v])) {
                if (C[p] > 1 + C[p-d[v]]) {
                    C[p] = 1 + C[p-d[v]];
                    S[p] = v;
                }
            }
        }
    }

    // fill values of change vector
    while (A>0) {
        change.push_back( d[S[A]] );
        A -= d[S[A]];
    }
    return C[C.size()-1];
}

void test_makeChange()
{
    vu cent_denom{1,5,10,25};
    vu dollar_denom{1,5,10,20,50,100};
    uint A = 17;

    cout <<"Number of coin for " << A <<" cent = " << makeChange(cent_denom, A);
    cout << endl;

    vu C;
    double amount = 187.87;
    uint dollars = static_cast<uint>(amount);
    uint cents = static_cast<uint>((amount - dollars)*100);
    cout <<"Change for " << amount <<":" << endl;
    cout <<"--- dollar bills: " << makeChange_dp(dollar_denom, dollars, C) << " bills, they are : ";
    copy (C.begin(), C.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    C.clear();

    cout <<"--- coin change : " << makeChange_dp(cent_denom, cents, C) << " coins, they are : ";
    copy (C.begin(), C.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << endl;
}

