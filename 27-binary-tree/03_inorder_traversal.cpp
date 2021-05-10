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

void inorder(node *root)
{
    //left->centre->right
    if (root->left != NULL)
        inorder(root->left);
    cout << root->data << ' ';
    if (root->right != NULL)
        inorder(root->right);
}

int main()
{
    /*
    
    Creating this binary tree
    
        1
       / \
      2   5
     / \ / \
    3  4 6  7
    
    */

    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    inorder(root);
}