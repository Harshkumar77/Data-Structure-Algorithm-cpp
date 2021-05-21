#include <iostream>
#include <climits>
using namespace std;
/**
 * Program to build BST from its inorder sequence
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
/*
1. Finding the middle of the array
2. Left half of the array would contribute to left subtree and
    right half would be right and the middle will become root node
*/
node *buildFromSortedArray(int inorder[], int l, int r)
{
    if (l > r) // base case
        return NULL;
    int mid = (l + r) / 2; // middle index
    node *root = new node(inorder[mid]);
    root->left = buildFromSortedArray(inorder, l, mid - 1);
    root->right = buildFromSortedArray(inorder, mid + 1, r);
}

void printInorder(node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << ' ';
    printInorder(root->right);
}

int main()
{
    int inorder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    node *root = buildFromSortedArray(inorder, 0, sizeof(inorder) / 4 - 1);
    printInorder(root), cout << '\n';
}