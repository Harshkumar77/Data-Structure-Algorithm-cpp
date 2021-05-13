/**

Program to find distance between two nodes of a binary tree 

Time Complexity -> O(N)
Space Complexity -> O(1)


 **/
#include <iostream>
#include <vector>
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

int distanceFromRoot(node *root, node *a)
{
    if (root == NULL)
        return -1;
    int dist = -1;
    if (root == a)
    {
        //base case
        dist = 0;
    }
    /*
    Checking if distance is >= 0 
    because if the key node is not present in the root it will return the distance -2
    */
    else if (distanceFromRoot(root->left, a) >= 0)
    {
        dist = 1 + distanceFromRoot(root->left, a);
    }
    else if (distanceFromRoot(root->right, a) >= 0)
    {
        dist = 1 + distanceFromRoot(root->right, a);
    }
    return dist;
}

node *LowestCommonAncestor(node *root, node *a, node *b)
{

    if (root == a or root == b or root == NULL)
    {
        //base case
        return root;
    }
    /*
    Checking for lowest common ancestor in both left and right part of Binary tree
    Results and conclusion : 
    
    1. Any one of the subtree is NULL
    👉 It is sure that LCA would not be present in non null part

    2. Both are NULL
    👉 Invalid entry or nodes passed in arguments are not present in tree
    
    3. None of them are non null
    👉 The current root node is the LCA
    
    */
    node *leftLCA = LowestCommonAncestor(root->left, a, b);
    node *rightLCA = LowestCommonAncestor(root->right, a, b);
    if (leftLCA == NULL and rightLCA != NULL)
    {
        return LowestCommonAncestor(root->right, a, b);
    }
    else if (leftLCA != NULL and rightLCA == NULL)
    {
        return LowestCommonAncestor(root->left, a, b);
    }
    else if (leftLCA != NULL and rightLCA != NULL)
    {
        return root;
    }
    return NULL;
}

int shortestDistance(node *a, node *b, node *root)
{
    /*
    Intution : line of shortest distance between 2 nodes must pass from their lowest common ancestor
    Algorithm :
        1. Finding the lowest common ancestor 
        2. Returning the sum of distance from node to LCA

    */
    if (a == NULL or b == NULL or root == NULL)
        return -1; // Checking for invalid inputs
    node *LCA = LowestCommonAncestor(root, a, b);
    return distanceFromRoot(LCA, a) + distanceFromRoot(LCA, b);
}

int main()
{
    /*
    
    Creating this binary tree
    
        *      1
        *     / \
        *    2   3
        *   / \ / 
        *  4  5 6  
        *   \    \
        *    8     9
    
    */

    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->left->right = new node(8);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->left->right = new node(9);

    cout << shortestDistance(root->right->left->right, root->left->left->right, root);
    // distance between 8 and 9
}
