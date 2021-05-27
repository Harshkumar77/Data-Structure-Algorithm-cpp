#include <iostream>

using namespace std;
/**
 * Program to recover BST from the distorted BST where two elements are swapped
 * 
 * Time complexity = O(n)
 * Space complexity = O(n)
 * 
 * optimal space solution can be found using Morris traversal
 *       
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

node *a = NULL, *b = NULL, *pre = new node(INT16_MIN);
/**
 * Intution : 
 *  the inorder of BST is always sorted 
 *  thatwhy the element not following this sorting would be responsible for the anomoly
 * 
 * We traverse in inorder fashion 
 * the two numbers not following the inorder fashion get swapped
*/
void traverse(node *root)
{
    if (root == NULL)
        return;
    traverse(root->left);
    if (a == NULL and pre->data > root->data)
        a = pre; // here pre is assigned because the first anomly in inorder sequence would be caused due to element
    // which is larger then the neighbours
    //example 1 4 2 - here 4
    if (a != NULL and pre->data > root->data)
        b = root; // here root is assigned because the second anomly in inorder sequence would be caused due to element
    // which is smaller then the neighbours
    //example 6 4 8 - here 4
    pre = root;
    traverse(root->right);
}
/**
 * -> We find the two nodes not in their correct position
 * -> We swap there data
 *  */
void recover(node *root)
{
    if (root == NULL)
        return;
    traverse(root);
    int x = a->data;
    a->data = b->data;
    b->data = x;
}
void printInorder(node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}
int main()
{
    /*
    *         Creating this BST
    *               _6_
    *              /   \__
    *            _3_      8
    *           /   \    / \
    *          1     9  7   5
    *           \    /       
    *            2  4
    */
    node *root1 = new node(6);
    root1->left = new node(3, new node(1, NULL, new node(2)), new node(9, new node(4), NULL));
    root1->right = new node(8, new node(7), new node(5));
    printInorder(root1);
    printf("\n");
    recover(root1);
    printInorder(root1);
}