/**

Program to find all the nodes from a node at distance k [Ancestor + subtree]

Time Complexity -> O(N)
Space Complexity -> O(1)


 **/
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

int maxSumPath(node *root, int &s)
{
    int ml = 0;
    int mr = 0;
    if (root->left)
        maxSumPath(root->left, ml);
    if (root->right)
        maxSumPath(root->right, mr);
    s = max(root->data, max(root->data + ml, root->data + mr));
    return max(root->data + ml + mr, max(root->data, max(root->data + ml, root->data + mr)));
}
int main()
{
    /*
    
    Creating this binary tree
        * * * * * * * * * *
        *        1        *    
        *       / \       *
        *      2   3      *
        *     / \ / \     *    
        *   -4  5 -6  7   *
        *   / \     \     *
        * -10  8     9    *
        * * * * * * * * * *

    */

    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(-4);
    root->left->left->left = new node(-10);
    root->left->left->right = new node(8);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->right = new node(7);
    root->right->left = new node(-6);
    root->right->left->right = new node(9);
    int s = 0;
    cout << maxSumPath(root, s);
}
