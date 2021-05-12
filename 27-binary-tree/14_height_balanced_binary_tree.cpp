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
};

bool isHeightBalanced(node *&root, int *h)
{
    if (root == NULL)
    {
        *h = 0;
        return true;
    }
    int lh = 0, rh = 0;
    if (!isHeightBalanced(root->left, &lh))
        return false;
    if (!isHeightBalanced(root->right, &rh))
        return false;
    *h = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
        return true;
    return false;
}

int main()
{
    /*
    
    Creating this binary tree
        1
       / \
      2   3
     / \ / \
    4  5 6  7

    */

    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    int h = 0;
    cout << isHeightBalanced(root, &h);
}
