/**
There is an array A[N] of N numbers. 
You have to compose an array Output[N] such that Output[i] will be equal to 
multiplication of all the elements of A[N] except A[i]. 
For example Output[0] will be multiplication of A[1] to A[N-1] and Output[1] will be 
multiplication of A[0] and from A[2] to A[N-1]. Solve it without division operator and
in O(N).
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

using namespace std;

long makeMultiplativeOutput ( vector<long>& v, size_t idx, long sofar )
{
  long cur_v = v[idx];
  
  if ( idx==v.size() ) {
    v[idx] = sofar;
    return cur_v;
  }
  
  // when going forwards multiply v[idx] to sofar
  long res = makeMultiplativeOutput(v,1+idx,sofar*cur_v);
  v[idx] = sofar * res;
  
  // when return multiply return value with v[idx]
  return cur_v * res;
}

int mail()
{
  vector<long> v{2,3,1,2};
  makeMultiplativeOutput(v, 0, 1);
}
