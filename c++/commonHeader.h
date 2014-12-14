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

typedef unsigned int uint;
using namespace std;

template<typename T> void printArray(const vector<T> &v, int lo=0, int hi=0);
template<typename T> void printVector(const vector<T> &v, int lo=0, int hi=0);
template<typename T> void printMatrix(const vector<vector<T>>&, int row=0, int col=0);

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (auto& el : vec) {
        os << "[" << el << "] ";
    }
    return os;
}

//////////////////////////////////////////////////////
typedef vector<vector<int>> Matrix;

template<typename T> void printVector(const vector<T> &v, int lo, int hi)
{
    if (lo*hi<0 || hi-lo<0) return;

    auto start = std::next(v.begin(),lo);
    auto end = std::next(v.begin(),hi);

	cout<<endl;
	cout<<"[ ";
    
 	for (auto it=start; it!=end; ++it) {
   		 cout<< *it << ", ";
   	}
	cout<<"]"<<endl;
}

void print(const Matrix& m) 
{ 
	for (size_t i=0; i<m.size(); ++i) { 
		cout<<endl; 
		for (size_t j=0; j<m[0].size();++j) 
			cout<<m[i][j] <<" "; 
		} 
	cout<<endl; 

}

template<typename T> T Max(T x, T y)
{
	return (x >= y) ? x : y;
}

template<typename T> void printMatrix(const vector<vector<T>>& v, int row, int col) const
{
	for( auto j=0; j<col; ++j ) {
   	 cout<<endl;
   	 for ( auto i=0; i<row; ++i ) {
   		 cout<<v[j][i]<<" ";
   	 }
	}
}

