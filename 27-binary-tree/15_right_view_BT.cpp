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

void rightViewOfBT(node *root)
{
    int n;
    queue<node *> q;
    q.push(root);
    node *a;
    while (!q.empty())
    {
        n = q.size();
        for (int i = 0; i < n; i++)
        {
            a = q.front();
            q.pop();
            if (i == n - 1)
                cout << a->data << ' ';
            if (a->left)
                q.push(a->left);
            if (a->right)
                q.push(a->right);
        }
    }
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

    rightViewOfBT(root);
}
