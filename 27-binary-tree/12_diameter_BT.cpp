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

int diameter(node *root, int *height)
{
    int lh = 0, rh = 0;
    int lDiameter = 0, rDiameter = 0;

    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    lDiameter = diameter(root->left, &lh);
    rDiameter = diameter(root->right, &rh);
    *height = max(lh, rh) + 1;
    return max(lh + rh + 1, max(lDiameter, rDiameter));
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

    int h = 0;
    cout << diameter(root, &h);
}
