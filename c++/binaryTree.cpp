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

    Node():value(0), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(T v):value(v), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(T v, Node<T> *l=nullptr, Node<T> *r=nullptr, Node<T> *p=nullptr) 
        : value(v), left(l), right(r), parent(p){}
    friend ostream& operator<<(ostream& os, const Node<int>& n);
};

ostream& operator<<(ostream& os, const Node<int>& n)
{
    os<<"[" << n.value << "]";
    return os;
}

template<class T> class binaryTree
{
    public:
        binaryTree():root(),count(0){}
        virtual ~binaryTree();
        virtual void insert (T);
        void deleteNode (T);
        void inorder ();
        bool isLeaf (Node<T>*);
        Node<T>* successor (Node<T>*);
        Node<T>* predecessor (Node<T>*);
        Node<T>* find (T v);

    protected:
        void inorder (Node<int>*);
        Node<T>* find_recur (Node<T>*,T);
        virtual Node<int>* insert (Node<int>*, int);
        virtual void delTree (Node<T>*);

        Node<T> *root;
        uint count;
};

template<> class binaryTree <int>
{
    public:
        binaryTree():root(),count(0){}
        virtual ~binaryTree();
        virtual void insert (int);
        void deleteNode (int);
        void inorder ();
        bool isLeaf (Node<int>*);
        Node<int>* successor (Node<int>*);
        Node<int>* predecessor (Node<int>*);
        Node<int>* find (int v);

    protected:
        void inorder (Node<int>*);
        Node<int>* find_recur (Node<int>*,int);
        virtual Node<int>* insert (Node<int>*, int);
        virtual void delTree (Node<int>*);

        Node<int> *root;
        uint count;
};

binaryTree::~binaryTree ()
{
    delTree (root);
}

void binaryTree<int>::delTree (Node<int>* node)
{
    if (node==nullptr) return;
    else {
        delTree (node->left);
        delTree (node->right);
        delete node;
    }
}

Node<int>* binaryTree<int>::successor (Node<int>* root)
{
    Node<int>* p;
    if (root->right != nullptr) {
        p = root->right;
        while (p->left!=nullptr) {
            p = p->left;
        }
    } else {
        p = root->parent;
        while (p!=nullptr) {
            if (root==p->left) break;
            root = p;
            p = p->parent;
        }
    }

    return p;
}

Node<int>* binaryTree<int>::predecessor (Node<int>* root)
{
    Node<int>* p;

    if (root->left != nullptr) {
        p = root->left;
        while (p->right!=nullptr) p = p->right;
    } else {
        p = root->parent;
        while (root!=nullptr) {
            if (root==p->right) break;
            root = p;
            p = p->parent;
        }
    }
    return p;
}

bool binaryTree<int>::isLeaf (Node<int>* root)
{
    return root->left==nullptr && root->right==nullptr;
}

Node<int>* binaryTree<int>::insert (Node<int>* root, int v)
{
    if (root==nullptr) {
        Node<int>* n = new Node<int>();
        n->value = v;
        ++count;
        return n;
    } 
    else if (root->value <= v) root = insert(root->left,v);
    else root = insert(root->right, v);
}

void binaryTree<int>::insert (int v)
{
    if (root==nullptr) {
        Node<int>* n = new Node<int>();
        n->value = v;
        root = n;
        ++count;
    } else {
        if (root->value <= v) root = insert(root->left,v);
        else root = insert(root->right, v);
    }
}

void binaryTree<int>::inorder (Node<int>* root)
{
    if (root==nullptr) return;
    inorder(root->left);
    cout<<root->value;
    inorder(root->right);
}

void binaryTree<int>::inorder ()
{
    inorder(root);
}

void binaryTree<int>::deleteNode (int v)
{

}

Node<int>* binaryTree<int>::find_recur (Node<int>* root, int v)
{
    if (root==nullptr) return nullptr;

    if (v==root->value) return root;
    else if (v < root->value)
        return find_recur (root->left,v);
    else return find_recur (root->right,v);
}

Node<int>* binaryTree<int>::find (int v)
{
    Node<int>* t = root;

    //return find_recur (t,v);
    while (t!=nullptr) {
        if (v==t->value) break;
        else if (v<t->value) t = t->left;
        else t = t->right;
    }

    return t;
}

/*************************************************************/
   
int main()
{
    vector<int>v{9,2,8,3,19,4,5,10,11,30,1};
    binaryTree<int> *tree = new binaryTree<int>();

    for (auto x:v) tree->insert(x);

    cout<<"\nInorder traversal: ";
    tree->inorder();
    cout<<endl;
}
