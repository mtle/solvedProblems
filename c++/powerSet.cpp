/***
 * Powerset Algorithm in C++
 * A powerset of a given set is the combination of all subsets, 
 * including the empty subset and the set itself. Suppose we 
 * have the following set: {1,2,3}. Its powerset would be:
 *
 * {1,2,3} 
 * {1,2}
 * {1,3}
 * {2,3}
 * {1}
 * {2}
 * {3}
 * Creating an algorithm to generate a powerset is not trivial. 
 * The first idea you can use is to implement an iterative algorithm 
 * that uses a stack to grow and shrink the set as needed. The 
 * benefit of this approach is that it prints the subsets in 
 * lexicographic order.
 *
 *
 * */
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

template<typename T> void pretty_print(const vector<T>& v) 
{
	cout << "{"; 
	copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, ",")); 
    cout << "}" << endl; 
}

template<typename T, typename U>
void combination(int offset, int k, vector<T>&A, vector<U>& res) 
{
 if (k == 0) { 
 	cout<<"{ ";
	copy(res.begin(), res.end(), std::ostream_iterator<T>(std::cout, " "));
	cout<<" }" << endl;
    return; 
    } 
 for (size_t i = offset; i <= A.size() - k; ++i) { 
    res.push_back(A[i]); 
    combination(i+1, k-1, A, res); 
    res.pop_back();
 } 
} 

template<typename T> void nCr(int n, int r, vector<T>& A)
{
	vector<T> res;
	combination(0, r, A, res);
}
void test_combination() 
{

vector<int> A; 

 int n = 5, r = 3; 
 for (int i = 0; i < n; ++i) {
   A.push_back(i+'A'); 
  } 
  nCr(0, r, A); 
}

template<typename T> void powerSet (vector<T>& A, int r) 
{
	if ( r==0 ) {
		cout<<"{}"<< endl;
		return;
	}
	powerSet(A, r-1);
	nCr(A.size(), r, A);
} 

template<typename T> void powerSet (vector<T>& s)
{
	powerSet(s, s.size());
}
void test_powerSet() 
{
  vector<int>v;
  int arr[] = {4,5,6,7,8,9,1,2,3};

  for(int i=0;i<9;++i) v.push_back(arr[i]);
 

  //test_combination();
  
  vector<char> A{'A','B','C'};
  powerSet(A);
  
} 
