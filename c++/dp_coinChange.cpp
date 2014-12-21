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
 * Given a number S and coins of values V = {V1,V2,V3, V4}.
 * Find number of ways change can be made for S using these coins.
 * We have infinite supply of these coins.
 * For example,
 * S = 4, V = {1,2,3}, there are four solutions: 
 *      {1,1,1,1},{1,1,2},{2,2},{1,3}
 */
 
template<typename T> T coinChange (const vector<T>&, T);
template<typename T> T coinChange_dp (const vector<T>&, T);

/**
 * Let C[p] be the minimum number of coins needed to make change for
 * p cents.
 *
 * Let x be the value of the first coin used in the optimal solution.
 * Then Cp] = 1 + C[p − x] .
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
template<> uint coinChange<uint> (const vi& V, uint A)
{
    if (A<0) return INT_MAX;
    if (A==0) return 0;
    else {
        vi C;
        for (auto x : V) C.push_back(1 + coinChange (V,A - x));
        sort (C.begin(), C.end());
        return 1 + C[0];
    }
}

template<> uint coinChange<uint> (const vi& V, uint A, vi& C, vi& S)
{
    if ( V.empty() || A<=0) return 0;
    // C : vector of number of coins
    // S : vector of coins [values] used
    for (int p=1; p<=A; ++p) {
        int coin, min = INT_MAX;
        for (auto v : V) {
            if (v<p) {
                if (min > 1+C[p-x]) {
                    min = 1 + C[p-x];
                    coin = v;
                }
            }
        }
        C.push_back(min);
        S.push_back(coin);
    }
    return C.back();
}

void test_coinChange()
{
    vi V{1,5,10,25};
    uint A = 77;

    cout <<"Number of coin for 77 cent = " << coinChange(V, A);
    cout << endl;

    vi C, S;

    cout <<"Number of coin for 77 cent [dp] = " << coinChange_dp(V, A, C, S);
    cout << endl;

    copy (S.begin(), S.end(), ostream_iterator(cout, " "));
    cout << endl;
}

