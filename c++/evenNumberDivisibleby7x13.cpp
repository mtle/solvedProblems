/**
  Count the number of even-digit numbers below 10^9 that are divisible by 7 and 13.
  
  Approach: since 7 and 13 are primes, a number that is divisible by 7 and 13 must devide 7*13=91
  1.  find all numbers that devide 91
  2.  number of digits of a number is d = floor(log(n)) + 1
  3.  if d%2==0 print/add number for output
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
#include <iterator>
#include <utility>
#include <bitset>
#include <stdexcept>
#include <cassert>
#include <climits>

using namespace std;

template<typename T> void evenNumberDivisibleby7x13(T n)
{
  vector<T> v;
  v.push_back(91);
  
  for (T x=91; x<=n; x+=x) {
    int d = log10(x) + 1;
    if (d%2 == 0) v.push_back(x);
  } 
  copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout,"\n"));
}

int main()
{
  unsigned long n = 1000000000;
  evenNumberDivisibleby7x13<unsigned long>(n);
}
