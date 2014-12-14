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
};

struct rect
{
    Point upper, lower;
    int width, length;
    rect():upper(0,0),lower(0,0){}
    rect(int x1, int y1, int x2, int y2) 
        : upper(x1,y1),lower(x2,y2),
          width(x2-x1),length(y2-y1)
        {}
};

bool isOverlap (const rect& a, const rect& b)
{
// if a.upper.x > b.lower.x
// if a.lower.x < b.upper.x
// if a.upper.y < b.lower.y
// if a.lower.y > b.upper.y
  
    if (a.upper.x > b.lower.x || a.lower.x < b.upper.x ||
        a.upper.y < b.lower.y ||  a.lower.y > b.upper.y)
        return false;
    else return true;
  
}

rect overlapRect (const rect& a, const rect& b)
{
    rect c;

    if (a.upper.x >= b.upper.x && b.upper.x >= a.lower.x) {
        c.upper.x = b.upper.x;
        c.lower.x = a.lower.x;
        if (b.upper.y < a.upper.y) {
            c.upper.y = b.upper.y;
            c.lower.y = a.lower.y;
        } else {
            c.upper.y = a.upper.y;
            c.lower.y = a.lower.y;
        }
    }
    return c;
}

int test_rect()
{

}

