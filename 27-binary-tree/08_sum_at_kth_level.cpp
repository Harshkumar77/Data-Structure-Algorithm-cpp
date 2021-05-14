#include <iostream>
#include <vector>
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
int nodeSum(node *root, int level)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int sum = 0, l = 0;
    while (!q.empty())
    {
        node *a = q.front();
        q.pop();
        if (a == NULL and !q.empty())
        {
            q.push(NULL);
            l++;
            if (l == level)
                return sum;
            sum = 0;
        }
        else if (not q.empty())
        {
            sum += a->data;
            if (a->left != NULL)
                q.push(a->left);
            if (a->right != NULL)
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

    cout << nodeSum(root, 2);
}
