/**

Program to flatten a binary tree in preorder manner
but 
-> Without using any other data structure and extra space

Time Complexity -> O(N)
Space Complexity -> O(N)


 **/
#include <iostream>
#include <vector>
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

void flattenBT(node *root)
{
    /*
    Simple recursive algorithm
        1. Flattening left subtree 
        2. Flattening right subtree
        3. Joining them in preorder manner 
    */
    node *l = root->left, *r = root->right;
    if (l != NULL)
        flattenBT(l);
    if (r != NULL)
        flattenBT(r);
    if (l != NULL)
    {
        root->right = l;
        root->left = NULL;
        while (l->right != NULL)
            l = l->right;
        l->right = r;
    }
    else
        root->right = r;
}

int main()
{
    /*
    
    Creating this binary tree
    
        *       1
        *      / \
        *     2   3
        *    / \ / \
        *   4  5 6  7
        *  / \    \
        * 10  8     9
    
    */

    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->left->left = new node(10);
    root->left->left->right = new node(8);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->right = new node(7);
    root->right->left = new node(6);
    root->right->left->right = new node(9);

    flattenBT(root);

    for (; root != NULL; root = root->right)
        cout << root->data << ' ';
}
