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
#include <utility>
#include <iterator>
#include <stack>
#include <stdexcept>
#include <cassert>

using namespace std;


/**
 * Given a string of brackets "{,(,[,],),}".  Determine if the brackets 
 * are paired correctly.
 * e.g.:    ({[()]}) = matched
 *          ()[]{}[] = matched
 *          ([]{})[] = matched
 *          ({[()]}] = not matched
 */ 
bool isMatched (const string& str)
{

    if ( str.empty()==true ) return true;

    stack<char> S;

    for ( auto it=str.begin(); it!=str.end(); ++it ) {
        if ( S.empty() == true ) {
            S.push(*it);
        } else {
            swicth (*it) {
                case ']' :
                    if ( S.top()=='[' ) S.pop();
                break;
                case '}' :
                    if ( S.top()=='{' ) S.pop();
                break;
                case '(' :
                    if ( S.top()=='(' ) S.pop();
                break;
                default :
                    S.push(*it);
                break;

            } // end switch
        }
    }
    if ( S.empty() ) return true;
    return false;
}
