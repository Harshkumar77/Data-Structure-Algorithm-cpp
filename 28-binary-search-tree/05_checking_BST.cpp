#include <iostream>
#include <climits>
using namespace std;
/**
 * Program to build BST from its preorder sequence
 * 
 * Time complexity = O(n)
 * Space complexity = O(n)
 *       
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

bool IsBST(node *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
        return true;
    return (root->data < max) and (root->data > min) and
           IsBST(root->left, min, root->data) and IsBST(root->right, root->data, max);
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

    IsBST(root1) ? cout << "BST" : cout << "Not BST";
    IsBST(root) ? cout << "\nBST" : cout << "\nNot BST";
}