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
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *a = q.front();
        q.pop();
        if (a == NULL and q.empty())
        {
            cout << '\n';
            return;
        }
        else if (a == NULL and not q.empty())
        {
            q.push(NULL);
            cout << '\n';
        }
        else
        {
            cout << a->data << ' ';
            if (a->left)
                q.push(a->left);
            if (a->right)
                q.push(a->right);
        }
    }
}
void SumReplacement(node *&root)
{
    if (root == NULL)
        return;
    SumReplacement(root->left);
    SumReplacement(root->right);
    if (root->left != NULL)
        root->data += root->left->data;
    if (root->right != NULL)
        root->data += root->right->data;
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
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    SumReplacement(root);

    levelOrderTraversal(root);
}
