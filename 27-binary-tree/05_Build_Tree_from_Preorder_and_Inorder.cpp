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

int search(int a[], int l, int r, int k)
{
    for (int i = l; i <= r; ++i)
        if (a[i] == k)
            return i;
    return -1;
}
node *buildTree(int preorder[], int inorder[], int start, int end, int &idx)
{
    if (start > end)
        return NULL;
    int curr = preorder[idx];
    node *root = new node(curr);
    idx++;
    if (start == end)
        return root;
    int x = search(inorder, start, end, curr);
    root->left = buildTree(preorder, inorder, start, x - 1, idx);
    root->right = buildTree(preorder, inorder, x + 1, end, idx);
    return root;
}
void inorder(node *root)
{
    //left->centre->right
    if (root->left != NULL)
        inorder(root->left);
    cout << root->data << ' ';
    if (root->right != NULL)
        inorder(root->right);
}
int main()
{
    int p[] = {1, 2, 3, 4, 5, 6, 7};
    int i[] = {3, 2, 4, 1, 6, 5, 7};
    int ii = 0;
    node *a = buildTree(p, i, 0, 6, ii);
    inorder(a);
    return 0;
}
