#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
    }
};

int main()
{
    /*
    
    Creating this binary tree
    
        1
       / \
      2   3
     / \ / 
    4  5 6  
    
    */

    node *root = new node(1);
    root->left->data = 2;
    root->left->left->data = 4;
    root->left->right->data = 5;
    root->right->data = 3;
    root->right->left->data = 6;
}
