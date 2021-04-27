#include <iostream>
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

void preorder(node *root)
{
    //centre->left->right
    cout << root->data << ' ';
    if (root->left != NULL)
        preorder(root->left);
    if (root->right != NULL)
        preorder(root->right);
}

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
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);

    preorder(root);
}
