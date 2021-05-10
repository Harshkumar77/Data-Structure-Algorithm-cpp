#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;

    node(int val)
    {
        data = val;
    }
};

bool isHeightBalanced(node *&root)
{
}

int main()
{
    /*
    
    Creating this binary tree
        1
       / \
      2   3
     / \ / \
    4  5 6  7

    */

    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << isHeightBalanced(root);
}
