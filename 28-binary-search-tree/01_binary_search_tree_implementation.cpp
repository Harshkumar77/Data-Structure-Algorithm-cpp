#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
*        Binary search tree is just normal binary tree                  
*           1. All the Left subtree's nodes value must be less than the parent node            
*           2. All the Right subtree's nodes node value must be greater than the parent node        
*           3. No duplicates must be there in tree                      
*
*        Program to build BST from an array.
*/
struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;
    node(int val)
    {
        data = val;
    }
    node(int val, node *a, node *b)
    {
        data = val;
        left = a;
        right = b;
    }
};

void insertNode(node *root, int value)
{
    /*
        Using properties of BST to inserting nodes
    */
    if (value < root->data)
    {
        if (root->left == NULL)
            root->left = new node(value);
        else
            insertNode(root->left, value);
    }
    else if (root->right == NULL)
        root->right = new node(value);
    else
        insertNode(root->right, value);
}

node *buildBST(vector<int> v)
{
    int n = v.size();
    if (n == 0)
        return NULL;
    node *root = new node(v[0]);
    for (int i = 1; i < n; i++)
        insertNode(root, v[i]);
    return root;
}

void printInorder(node *root)
{
    /*      Inorder of a BST is always *SORTED*    */
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << ' ';
    printInorder(root->right);
}

int main()
{
    vector<int> v = {5, 1, 4, 3, 2, 7, 6};
    printInorder(buildBST(v));
}