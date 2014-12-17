#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void permutation(int n, int r, vector<T>&a) 
//void permutation(int n, int r, vector<T>&a, vector<T>&res) 
{
    if (r==n) {
        cout <<"{";
        copy (a.begin(),a.end(),std::ostream<T>(std::cout," "));
        cout<<"}" << endl;
        return;
    }
    for (int i=r; i<n; ++i) {
        swap(a[i],a[r]);
        permutation(n,i+1,a);
        swap(a[i],a[r]);
    }
}

template<typename T>
void nPr(int n, int r, vector<T>&a) 
{
    if (n<=0 || r<0 || v.empty()) return;
    permutation(n,r,a);
}

template<typename T>
void combination(int n, int r, vector<T>&a, vector<T>&res) 
{
    if (r==n) {
        // print out one solution
        copy (res.begin(),res.end(),std::ostream_iterator<T>(std::cout," "));
        cout << endl;
        return;
    }
    for (int i=n; i<=a.size()-r; ++i) {
        // choose the first element
        res.push_back(a[i]);
        combination(i + 1, r - 1, a, res);
        res.pop_back();
    }
}

void combination(int n, int r, vector<char>&src, vector<char>&dst, int sz) {
    for (int i = n; i >= r; i --) {
        // choose the first element
        dst[r - 1] = src[i-1];
        if (r > 1) { // if still needs to choose
            // recursive into smaller problem
            combination(i - 1, r - 1, src, dst, sz);
        } else {
            // print out one solution
            for (int i = 0; i < sz; i ++) {
                cout << dst[i] << " ";
            }
            cout << endl;
        }
    }
}

void test_Perm_Comb () 
{
    const int N = 5;
    const int R = 3;
    //int *arr = new int[R];
    //comb(N, R, arr, R);
    
    vector<char>src{'a','b','c','d','e'};
    vector<char>dst(R,0);
    
    combination(N, R, src, dst, R);
    
    
    return 0;
}
