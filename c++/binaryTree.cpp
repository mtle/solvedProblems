/**
1. Check if binary tree is balanced or not?
2. Zig Zag order traversal of tree.
3. Prune all nodes of tree which are outside a range min and max.
4. Find least common ancestor.
5. Replace nod with sum of children.
6. Convert tree to DLL.
7. Print last K nodes of binary search tree.
8. Find pair of nodes with given sum.
9. Level order traversal of tree.
10.Build tree from given pre-order and inroder traversal.
11. Tree traversals without recursion.
12. Find paths in binary search tree of given sum.
13. Calculate number of trees with N nodes. 
14. Print right view of binary search tree.
15. Vertical sum of binary search tree.

http://algorithmsandme.blogspot.ca/p/blog-page_27.html#.VIySytLF94h
*/

#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <unordered_map>
#include <cassert>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename valueType> struct Node
{
  valueType value;
  Node<valueType> *left, *right;
  Node(valueType v):value(v), left(nullptr), right(nullptr) {}
  Node(valueType v, Node<valueType> *l=nullptr, Node<valueType> *r=nullptr) 
    : value(v), left(l), right(r){}
};


int main()
{
}
