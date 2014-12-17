/***
  Given two axis-aligned rectangles A and B. Write a function to determine 
  if the two rectangles overlap.

Hint:
If you are coming up with a complicated set of conditionals, you might think 
too hard. There is an easier way. Try to think in the opposite direction.

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
#include <iterator>
#include <bitset>
#include <stdexcept>
#include <cassert>

#ifndef uint
typedef unsigned int uint;
#endif

using namespace std;

struct Point
{
    int x, y;
    Point():x(0),y(0){}
    Point(int x_, int y_):x(x_),y(y_){}
    friend ostream& operator<<(ostream& os, Point const &p);
};

ostream& operator<<(ostream& os, Point const &p)
{
    os << "(" << p.x << "," <<p.y <<")";
    return os;
}

struct rect
{
    Point left, right;
    int width, length;
    rect():left(0,0),right(0,0){}
    rect(int x1, int y1, int x2, int y2) 
        : left(x1,y1),right(x2,y2),
          width(x2-x1),length(y2-y1)
        {}
    void setLeft (int,int);
    void setRight (int,int);
    friend ostream& operator<<(ostream& os, rect const &r);
};
ostream& operator<<(ostream& os, rect const &r)
{
    os << "{ " << r.left << ", " << r.right << " }" << endl;
    return os;
}
void rect::setLeft (int x, int y) {
    this->left.x = x;
    this->left.y = y;
}
void rect::setRight (int x, int y) {
    this->right.x = x;
    this->right.y = y;
}

bool isOverlap (const rect& a, const rect& b)
{
// if a.left.x >= b.right.x OR b.left.x >= a.right.x
// if a.right.y >= b.left.y OR b.right.y >= a.left.y
  
    if (a.right.x <= b.left.x || 
		b.right.x <= a.left.x ||
        a.right.y <= b.left.y || 
		b.right.y <= a.left.y)
        return false;
    else return true;
  
}

rect compute_overlapRect (const rect& a, const rect& b)
{
    rect c;

    if (a.left.x >= b.left.x && b.left.x >= a.right.x) {
        c.left.x = b.left.x;
        c.right.x = a.right.x;
        if (b.left.y < a.left.y) {
            c.left.y = b.left.y;
            c.right.y = a.right.y;
        } else {
            c.left.y = a.left.y;
            c.right.y = a.right.y;
        }
    }
    return c;
}

void test_rect()
{
	rect r1{0,0,4,4};
	rect r2{3,3,6,6};
	
	cout << r1 << r2;
  
	cout<<"Are the 2 rect overlap ? ";
	if (isOverlap (r1, r2)) cout<<"true" << endl;
	else cout<<"false" << endl;
	
	r2.setLeft(4,4);
	cout << r1 << r2;
	cout<<"Are the 2 rect overlap ? ";
	if (isOverlap (r1, r2)) cout<<"true" << endl;
	else cout<<"false" << endl;

}

int main()
{
    test_rect();
}

