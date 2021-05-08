#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;

    node(int val) { data = val; }
};

int search(int a[], int l, int r, int k)
{
    for (int i = l; i <= r; ++i)
        if (a[i] == k)
            return i;
    return -1;
}
node *buildTree(int postorder[], int inorder[], int start, int end, int &idx)
{
    node *root = NULL;
    if (start > end)
        return root;
    int curr = postorder[idx--];
    root = new node(curr);
    if (start == end)
        return root;
    int x = search(inorder, start, end, curr);
    root->right = buildTree(postorder, inorder, x + 1, end, idx);
    root->left = buildTree(postorder, inorder, start, x - 1, idx);
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
    int p[] = {3, 4, 2, 6, 7, 5, 1};
    int i[] = {3, 2, 4, 1, 6, 5, 7};
    int idx = 6;
    node *a = buildTree(p, i, 0, 6, idx);
    inorder(a);
    return 0;
}
