
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
#include <iterator>
#include <numeric>

using namespace std;

/** 5.1 COMPUTlNG PARITY
The parity of a sequence of bits is 1 if the number of 1s in the sequence is odd;
otherwise, it is O. Parity checks are used to detect single bit errors in data storage and
communication. Itis fairly straightforward to write code that computes the parity of
a single 64-bit nonnegative integer.

Problem 5.1: How would you go about computing the parity of a very large number
of 64-bit nonnegative integers?

*/

int bitCount( unsigned n)
{
  int count = 0;
  while (n) {
    ++count;
    n &= (n-1);
  }
  return count;
}
int parity(unsigned n)
{
  unsigned p = 0;
  while (n)) {
    p ^= 1;
    n &= (n-1);
  }
  return p;
}

void test_parity()
{
  unsigned n = 0x78f8ae928a7706cc;
  cout<<:\nparity = " << parity(n) << endl;
}
