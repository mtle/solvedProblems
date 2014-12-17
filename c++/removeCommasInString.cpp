/** REMOVING COMMAS
Given a char array {1,234,34,54}, modify the char array so 
that there is no comma in the most efficient way. We must
get a char array {12343454}
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

typedef unsigned int uint;
using namespace std;

void removeCommas (string& str)
{
    uint i,j;
    i = j = 0;

    while (i<str.size()) {
        if (str[i]==',') ++i;
        str[j++] = str[i++];
    }
    str[j] = '\0';
    str.resize();
}

void test_removeCommas();
{
    string s{"123,654,987,012};
    removeCommas(s);

    cout<<endl;
