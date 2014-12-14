/***
    Say you have an array for which the ith element is the 
    price of a given stock on day i.

    If you were only permitted to buy one share of the stock and 
    sell one share of the stock, design an algorithm to find the 
    best times to buy and sell.
    The question is equivalent to the following:
      Find i and j that maximizes Aj – Ai, where i < j.
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

template<typename T> void print(const vector<T>&);

///////////////////////////////////////////////////////////////////////
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (auto& el : vec) {
        os << "[" << el << "] ";
    }
    return os;
}
typedef vector<vector<int>> Matrix;

template<typename T> void print(const vector<T>& v)
{
	for (auto itr=v.begin(); itr!=v.end();++itr)
			cout<<*itr <<" ";
		
	cout<<endl;
}

template<typename T> T Max(T x, T y)
{
	return (x >= y) ? x : y;
}


template<typename T> T Min(T x, T y)
{
	return (x <= y) ? x : y;
}



/**************************************************************************/
int buySell(vector<int>& v)
{
	int max_profit=0;
	int profit;
	int buy=v[0];
	
	// v = 12, 7, 8, 15, 16, 11, 9, 10
	for (size_t x=1; x<v.size(); ++x) {
		profit = v[x] - buy;
        buy = Min(buy, v[x]);
		max_profit = Max(profit, max_profit);
	}
	return max_profit;
}

int main()
{
	vector<int>v{12,7,8,15,16,11,9,10};
	cout<<"max profit = " << buySell(v) << endl;
    
}