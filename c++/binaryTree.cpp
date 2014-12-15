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
#include <limits>
#include <vector>
#include <map>
#include <unordered_map>
#include <cassert>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename T> struct Node
{
  T value;
  Node<T> *left, *right, *parent;
  Node(T v):value(v), left(nullptr), right(nullptr), parent(nullptr) {}
  Node(T v, Node<T> *l=nullptr, Node<T> *r=nullptr, Node<T> *p=nullptr) 
    : value(v), left(l), right(r), parent(p){}
};

template<> class binaryTree <int>
{
    public:
        binaryTree():root(),count(0){}
        virtual ~binaryTree();
        virtual void insert(int);
        void deleteNode(int);
        void inorder();
        bool isLeaf(Node<int>*);
        Node<int>* successor(int);
        Node<int>* predecessor(int);

    protected:
        void inorder(Node<int>*);

        Node<int> *root;
        uint count;
};

template<> Node<int>* binaryTree<int>::successor(int v)
{
    return root->left==nullptr && root->right==nullptr;
}

template<> Node<int>* binaryTree<int>::predecessor(int v)
{
    return root->left==nullptr && root->right==nullptr;
}

template<> bool binaryTree<int>::isLeaf(Node<int>* root)
{
    return root->left==nullptr && root->right==nullptr;
}

template<> Node<int>* binaryTree<int>::insert(Node<int>* root, int v)
{
    if (root==nullptr) {
        Node<int>* n{v};
        return n;
    } 
    else if (root->value <= v) root = insert(root->left,v);
    else root = insert(root->right, v);
}

template<> void binaryTree<int>::insert(int v)
{
    if (root==nullptr) {
        Node<int>* n{v};
        root = n;
    } else {
        if (root->value <= v) root = insert(root->left,v);
        else root = insert(root->right, v);
    }
}

template<> void binaryTree<int>::inorder(Node<int>* root)
{
    if (root==nullptr) return;
    inorder(root->left);
    cout<<root;
    inorder(root->right);
}

template<> void binaryTree<int>::inorder()
{
    inorder(root);
}


/*************************************************************/
   
int main()
{
}
