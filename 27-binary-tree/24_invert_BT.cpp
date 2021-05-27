/**
 * Program to invert a binary tree
 * 
 * Time Complexity : O (n)
 * Space Complexity : O (n)
 * 
*/

#include <iostream>
#include <climits>

using namespace std;

struct node
{
    node *left = NULL, *right = NULL;
    int data;
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

node *invertBT(node *root)
{
    return root ? new node(root->data, invertBT(root->right), invertBT(root->left)) : root;
}

int main()
{

    /*
                        *         Creating this BST
                        *               _6_
                        *              /   \__
                        *            _3_      8
                        *           /   \    / \
                        *          1     5  7   9
                        *           \    /       
                        *            2  4
                        */
    node *root1 = new node(6);
    root1->left = new node(3, new node(1, NULL, new node(2)), new node(5, new node(4), NULL));
    root1->right = new node(8, new node(7), new node(9));
}