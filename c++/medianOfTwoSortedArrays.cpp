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

/** Problem statement
Given two sorted arrays, find the median of two arrays of equal size. 
Median of array of integers is middle of those integers if number of 
elements are odd and average of middle elements if number of elements 
is even.
For example if  A = {10,30,50, 60} and B = {30, 40, 100, 110} median 
will be (40+50)/2  = 45 as we if combine two sorted arrays 
C = {10,30,30,40,50,60,100, 110} and hence  length is even so median 
will be (c[mid] + c[mid+1])/2.
*/


