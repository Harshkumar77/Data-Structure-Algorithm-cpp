#include <iostream>
using namespace std;
/**
 * Program to delete a node in a BST
 * 
 * Time complexity = O(log n)
 * Space complexity = O(log n)
 * 
 * There could be three cases while deleting a node :
 * 
 * CASE 1 : Leaf node
 * ->   deleting it directly
 * CASE 2 : Any sub node is NULL
 * ->   replacing the node with its non null sub node
 * CASE 3 : None of the sub node in NULL
 * ->   1. Finding its inorder previous node or inorder next node (ANY ONE)
 *      2. Swaping the data of both nodes
 *      3. Recursively calling function for right subtree of the orignal node
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

node *inorderNext(node *b)
{
    //It is sure that inorder next of node A in BST would be present in left most
    //node of the A->right of A
    node *a = b;
    while (a != NULL and a->left != NULL)
        a = a->left;
    return a;
}

void deleteBST(node *&root, int key)
{
    if (key > root->data)
        deleteBST(root->right, key);
    else if (key < root->data)
        deleteBST(root->left, key);
    else
    {
        node *temp;
        if (root->left == NULL)
        {
            //case 1 and 2
            temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            // case 2
            temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            //case 3
            temp = inorderNext(root->right);
            int a = temp->data;
            temp->data = root->data;
            root->data = a;
            deleteBST(root->right, key);
        }
    }
}

void printInorder(node *root)
{
    /*      Inorder of a BST is always *SORTED*    */
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << ' ';
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
    *          1     5  7   9
    *           \    /       
    *            2  4
    */
    node *root = new node(6);
    root->left = new node(3, new node(1, NULL, new node(2)), new node(5, new node(4), NULL));
    root->right = new node(8, new node(7), new node(9));

    printInorder(root), cout << '\n';
    deleteBST(root, 6);
    printInorder(root), cout << '\n';
}