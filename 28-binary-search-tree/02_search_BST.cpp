/**
 * Program to search a node
 * 
 * Time complexity -> O(log n)
 * Space complexity -> O(log n)
*/

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
    node(int val, node *a, node *b)
    {
        data = val;
        left = a;
        right = b;
    }
};

node *searchNodeInBST(node *root, int key)
{
    /*
    Using properties of BST
    */
    if (root->data == key)
        return root;
    if (root->left != NULL and root->data > key)
        // if the key < current node data it must be on its left subtree
        return searchNodeInBST(root->left, key);
    return searchNodeInBST(root->right, key);
}

int main()
{
    /*
              Creating this BST
    *                6
    *              /   \
    *             3     8
    *            / \   / \
    *           1   5 7   9
    *              /
    *             4
    */
    node *root = new node(6);
    root->left = new node(3, new node(1), new node(5, new node(4), NULL));
    root->right = new node(8, new node(7), new node(9));
    cout << searchNodeInBST(root, 10)->data;
}