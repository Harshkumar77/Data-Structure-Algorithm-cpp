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

node *buildFromPreorder(int preorder[], int n, int &idx, int min = INT_MIN, int max = INT_MAX)
{
    /*

    Intutiion :
    In a node of a BST there would be a range for the nodes that can be present in its subtree

    Example : 
        5           * left subree of 5 can be in range (-♾ , 5) and right subtree of 5 can be in range (5,♾)
       / \          * LS of 3 (-♾,3)   
      3   7         * LS of 7 (5,7) RS of 7 (7,♾)
     /   / \        *     
    2   6   8       *     
    Algorithm :

    1. Creating root node the first element
    2. Recursively add next consecutive element in the tree using the property
    3. Then add elements to the right subtree recursively

    
    */
    if (idx >= n)
        return NULL;
    int key = preorder[idx];
    node *root;
    if (key < max and key > min)
    {
        root = new node(key), idx++;
        if (idx < n)
            root->left = buildFromPreorder(preorder, n, idx, min, key);
        if (idx < n)
            root->right = buildFromPreorder(preorder, n, idx, key, max);
    }

    return root;
}

void printPreorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << ' ';
    printPreorder(root->left);
    printPreorder(root->right);
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
    int preorder[] = {6, 3, 1, 2, 5, 6, 8, 7, 9};
    int idx = 0;
    node *root = buildFromPreorder(preorder, 9, idx);
    printPreorder(root), cout << '\n';
}