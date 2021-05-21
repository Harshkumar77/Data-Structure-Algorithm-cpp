/**
 * Program to build all the possible BST from sorted sequence
 * (in this case we are using ranges but question can be easily modified by using sorted array)
 * 
 * Time Complexity :
 * 
*/

#include <iostream>
#include <vector>
#define rep(a, b, i) for (int i = a; i < b; i++)
using namespace std;

struct node
{
    node *left = NULL, *right = NULL;
    int data;
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
/**
 * Intution : The total numbers of BST can be formed is equal to nth catalan number
 * 
 * Algorithm :
 * 
 * 1. Build every possible left and right subtree
 * 2. Summing them to create BST
 * 
 * NOTE : Every tree in BST by default because we are sending 
 *        smaller values(<i) in left and greater(>i) in right
*/
vector<node *> buildBST(int start, int end)
{
    vector<node *> trees, leftSubtree, rightSubtree;
    if (end < start)
    {
        trees.push_back(NULL);
        return trees;
    }
    rep(start, end + 1, i)
    {
        leftSubtree = buildBST(start, i - 1); // All possible left subtree
        rightSubtree = buildBST(i + 1, end);  // All possible right subtree
        rep(0, leftSubtree.size(), j)
            rep(0, rightSubtree.size(), k)
                trees.push_back(new node(i, leftSubtree[j], rightSubtree[k]));
        // joining them
    }
    return trees;
}
void printInorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << ' ';
    printInorder(root->left);
    printInorder(root->right);
}
int main()
{
    for (node *x : buildBST(1, 4))
        printInorder(x), cout << '\n';
}