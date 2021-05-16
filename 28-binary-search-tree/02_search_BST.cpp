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
    node(int val, node *a, node *b)
    {
        data = val;
        left = a;
        right = b;
    }
};

void printInorder(node *root)
{
    /*      Inorder of a BST is always *SORTED*    */
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << ' ';
    printInorder(root->right);
}

node *searchNodeInBST(node *root, int key)
{
    if (root->data == key)
        return root;
    if (root->left != NULL and root->data > key)
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
    printInorder(root);
    cout << '\n'
         << searchNodeInBST(root, 10)->data;
}