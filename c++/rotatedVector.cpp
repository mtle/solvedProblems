#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int findRotationCount (const vector<int>& v);

void printv(const vector<int>& v) 
{
   for(size_t i=0; i<v.size();++i) 
      cout<<v[i]<<" ";
    cout<<endl;           
} 

/*Given a rotated sorted array and count 'k' by which the array 
is rotated clockwise is not known, find Nth highest number. Assume that array was sorted in ascending order before rotation. For finding minimum element pass 'n' as 1 and for finding maximum pass 'n' as size.*/

int findNthHighest(const vector<int>& v, int N) 
{
  assert(N>0 && N<static_cast<int>(v.size()) );
 int count = findRotationCount(v);
 return v[v.size() - count -  N];
} 

// 456789123 lo=4 hi=3 mid=8
// 9123 lo=9 hi=3 mid=1
/*Given a rotated sorted array find the count by which the array is rotated. Array was sorted in ascending order before rotation and was rotated clockwise*/
int findRotationCount (const vector<int>& v) 
{
   int k=v.size() - 1, count=0;
   while (k>0) {
     if (v[k-1]>v[k]) break;
     --k;
     ++count;

  } 
   return count+1;              
} 

void reverseVector(vector<int>& v, int lo, int hi) 
{
  for(int i=lo,j=hi;i<=(lo+hi)/2;++i,--j) {
    swap(v[i],v[j]);
 }                    
} 
void rotateVector (vector<int>&v, int k)
{
  printv(v);
  reverseVector(v,0,v.size()-1);
   printv(v);
   reverseVector(v,0,v.size()-k-1);
    printv(v);
    reverseVector(v,v.size()-k,v.size()-1);   
    printv(v);  
} 

/**
 * This will fail for vectors with duplicates,
 * e.g. { 4,4,4,4,4,4,4,3,4,4 }
 * in this case v[lo] = v[hi] = v[mid]
 * */
int findRotationCount_bsearch (const vector<int>& v, int lo, int hi)
{
    uint mid = (lo + hi) / 2;

    cout<<"\nmid = " << mid << "  v[mid]=" << v[mid] << "  v[lo]=" << v[lo]<< "  v[hi]=" << v[hi];
    if (mid==lo || mid==hi) 
        return v[lo]>v[hi] ? hi : lo;
    else if (v[mid] == v[hi] && v[mid] == v[lo]) {
        int from_lo = findRotationCount_bsearch (v, lo, mid);
        int from_hi = findRotationCount_bsearch (v, mid+1, hi);
        
        cout<<"\nfrom_lo = " << from_lo << "\tfrom_hi = " << from_hi << endl;
        return v[from_lo]>v[from_hi] ? from_hi : from_lo;
    } else if (v[mid] > v[hi]) {
        return findRotationCount_bsearch (v, mid, hi);
    } else {
        return findRotationCount_bsearch (v, lo, mid);
    }
}

void test_rotateVector () 
{
  vector<int>v;
  int arr[] = {4,5,6,7,8,9,1,2,3};

  for(int i=0;i<9;++i) v.push_back(arr[i]);
  cout<<"3rd largest is " << findNthHighest(v, 3) <<endl;
  cout<<"the largest is " << findNthHighest(v,1)<<endl;

  v.clear();
  srand(time(NULL));
  for (int i=0; i<15;++i) v.push_back(rand() %53);
  sort(v.begin(), v.end());
  rotateVector(v, 4);

  cout<<"rotation cnt = "<<findRotationCount(v);
  cout<<"the largest is " << findNthHighest(v,3)<<endl;

} 
