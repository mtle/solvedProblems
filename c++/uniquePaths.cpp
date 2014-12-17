/***
A robot is located at the top-left corner of a m x n grid (marked 
‘Start’ in the diagram below). The robot can only move either down 
or right at any point in time. The robot is trying to reach the 
bottom-right corner of the grid (marked ‘Finish’ in the diagram below). 
How many possible unique paths are there?

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

template<typename T> void printArray(const vector<T> &v, int lo, int hi) const
{
	cout<<"\n[";
    if ( 0==lo && 0==hi ) {
   	 for ( auto x : v ) {
   		 cout<<x<<", ";
   	 }
    } else if ( lo>=0 && hi>0 ) {
   	 for (auto x=lo; x<=hi; ++x) {
   		 cout<<v.at(x) << ", ";
   	 }
    } else {
    	return;
	}
	cout<<"]"<<endl;
}

template<typename T> void printVector(const vector<T> &v, int lo, int hi) const
{
	cout<<"\n[";
    if ( 0==lo && 0==hi ) {
   	 for ( auto x : v ) {
   		 cout<<x<<", ";
   	 }
    } else if ( lo>=0 && hi>0 ) {
   	 for (auto x=lo; x<=hi; ++x) {
   		 cout<<v.at(x) << ", ";
   	 }
    } else {
    	return;
	}
	cout<<"]"<<endl;
}

template<typename T> T bt_dp(T x, T y, T r, int c)
{
	vector<int>w(c+2,0);
	vector<vector<int>>v(r+2,vector<int>(w));
	
	v[1][0] = 1;
			
	for (int i=1; i<=r+1; ++i)
		for (int j=1; j<=c+1; ++j)
			v[i][j] = v[i-1][j] + v[i][j-1];
			
	return v[r+1][c+1];
	
}

template<typename T> T bt(T x, T y, T m, T n) 
{
  if (x==m && y==n) return 1;
  else if (x>m || y>n) return 0;
  return bt(x+1,y,m,n) + bt(x,y+1,m,n);
}
template<typename T> T backtrack(T m, T n)
{
	return bt(0,0,m,n);
}

template<typename T>
int bt_memozation(T x, T y, T m, T n, vector<vector<T>>& mat)
{
    if (x==m && y==n) return 1;
    else if (x>m || y>n) return 0;
    
    if (mat[x+1][y] == -1) mat[x+1][y] = bt_memozation(x+1,y,m,n,mat);
    if (mat[x][y+1] == -1) mat[x][y+1] = bt_memozation(x,y+1,m,n,mat);
    
    return mat[x+1][y] + mat[x][y+1];
}

template<typename T> void bt_memozation(T x, T y)
{
    vector<vector<int>>mat(m+2,vector<int>(n+2,0));
    
    for (auto it=mat.begin(); it!=mat.end()-1; ++it) 
        for (auto itr=it->begin(); itr!=it->end()-1; ++itr)
            *itr = -1;
    print(mat);
    mat[0][0] = bt_memozation(0,0,x,x,mat);
    print(mat);
}
/*****************************************************************************/
void test_uniquePaths ()
{
	cout<<"backtrack(2,2): " << backtrack(2,2) << endl;
    cout<<"bt_dp(2,2): " << bt_dp(0,0,2,2) << endl;
}
