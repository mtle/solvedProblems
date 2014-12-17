#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <unordered_map>
#include <cassert>
#include <algorithm>
#include <iterator>

using namespace std;

//typedef pair<int,int> pii;

struct pii
{
	int first, second;
	pii() : first(0), second(0){}
	pii(int n1, int n2) : first(n1), second(n2){}
	friend std::ostream& operator<< (std::ostream& os, const pii& e);
};
std::ostream& operator<< (std::ostream& os, const pii& e)
{
	os << "(first,second) = (" << e.first << "," << e.second << ")" << endl;
	return os;
}

template<typename elemType>
elemType findFirstNonRepeatingElem (const vector<elemType>& s)
{
    //vector<pii> v(265,pii(0,0));
    vector<pii> v(265);
    for (size_t i=0; i<s.size(); ++i) {
        ++v[s[i]].first;
        v[s[i]].second = i;
    }
	
	copy(v.begin(), v.end(),std::ostream_iterator<pii>(cout,"\n"));
	
    int idx = INT_MAX;
    for (auto it=v.cbegin(); it!=v.cend(); ++it) {
        if (it->first == 1) {
            idx = min(idx, it->second);
        }
    }
    return s[idx];
}

template<typename elemType>
void findFirstNonrepeating (const vector<elemType>& s)
{
    if (s.empty()) return;
    unordered_map<elemType,pii>m;

    for (auto i=0; i<s.size(); ++i) {
        ++m[s[i]].first;
        m[s[i]].second = i;
    } 

    copy(m.begin(),m.end(),ostream_iterator<elemType,pii>(cout,"\n"));

    int idx = INT_MAX;
    for (auto it=m.cbegin();it!=m.cend();++it) {
        if (it->second.first==1) {
            idx = min(idx,it->second.second);
        }
    }
    cout<<endl;
    cout<<"the elem is " << s[idx] << endl;
}

void test_findFirstNonrepeating ();
{
    vector<char> s;
    string str("ABUD ABI abudabi UD");
	
	for (auto x : str ) s.push_back(x);
	
    findFirstNonrepeating(s);
    cout<<"\n" << findFirstNonRepeatingElem(s) << endl;
    
    vector<int> vi{2,3,4,5,6,11,4,9,8,2,3,5,6,11};
    findFirstNonrepeating(vi);
    cout<<"\n" << findFirstNonRepeatingElem(vi) << endl;

}
