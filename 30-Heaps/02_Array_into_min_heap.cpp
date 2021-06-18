#include <iostream>
#include <queue>
using namespace std;

/***
 * Program to convert array into balanced min heap
 * 
 * Time complexity : O(N)
 * Space complexity : O(N)
 * 
 * N-> Size of array
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

void levelOrderTraversal(node *root)
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
            cout << a->data << ' ';
            if (a->left)
                q.push(a->left);
            if (a->right)
                q.push(a->right);
        }
        cout << '\n';
    }
}

void addNode(node *&root, int val)
{
    if (root == NULL)
        root = new node(val);
    else if (root->data > val)
    {
        swap(root->data, val);
        if (root->left == NULL)
            addNode(root->left, val);
        else if (root->right == NULL)
            addNode(root->right, val);
        else if (root->left->data > root->right->data)
            addNode(root->left, val);
        else
            addNode(root->right, val);
    }
    else
    {
        if (root->left == NULL)
            addNode(root->left, val);
        else if (root->right == NULL)
            addNode(root->right, val);
        else if (root->left->data > root->right->data)
            addNode(root->left, val);
        else
            addNode(root->right, val);
    }
}

node *maxHeap(int a[], int N)
{
    node *root = NULL;
    for (int i = 0; i < N; i++)
        addNode(root, a[i]);
    return root;
}

int main()
{
    int a[] = {3, 4, 100, 10, 7, 11, 20, 12, 5, 2};
    node *t = maxHeap(a, sizeof a / 4);
    levelOrderTraversal(t);
}

/*

Recived output :

2 
4 3 
7 5 
12 11 10 
100 20

*/