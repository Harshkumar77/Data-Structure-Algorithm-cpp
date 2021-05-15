/**

Program to find all the nodes from a node at distance k [Ancestor + subtree]

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

void addSubtreeNodes(node *root, int k, vector<node *> &v)
{
    //program to find all the subtree nodes at distance k from root
    if (k == 0)
    {
        v.push_back(root);
        return;
    }
    /*
        1. Traversing whole tree using recursion
        2. At evey new level reducing value of k by 1
        3. When k == 0 adding / printing that node
    */
    if (root->left)
        addSubtreeNodes(root->left, k - 1, v);
    if (root->right)
        addSubtreeNodes(root->right, k - 1, v);
}

int addAncestorNodes(node *root, node *n, int k, vector<node *> &v)
{
    /*
    Algorithm :
        1. Traversing the left subtree for finding the distances of node n from all its ancestor
        2. From every ancestor right node printing/adding all nodes at distance k-distanceOfAncestorToTargetNode-2 
        3. If target node was not found in left subtree doing same procedure for right subtree
    */
    if (root == NULL)
        return -1;
    if (root == n)
        return 0;
    int distanceLeft = addAncestorNodes(root->left, n, k, v);
    if (distanceLeft != -1)
    {
        if (distanceLeft + 1 == k)
        // distanceLeft is distance from left node of root to target
        //thatswhy distanceLeft+1 would be distance from root to target
        {
            v.push_back(root);
        }
        else if (root->right) // if target is found is left we have to look for nodes in right and visa versa
        {
            addSubtreeNodes(root->right, k - distanceLeft - 2, v);
            // distance from left node to the right node of root is 2 thatswhy 2 is also subtracted
        }
    }
    else
    {
        int distanceRight = addAncestorNodes(root->left, n, k, v);
        if (distanceRight + 1 == k)
        {
            v.push_back(root);
        }
        else if (root->left)
        {
            addSubtreeNodes(root->left, k - distanceRight - 2, v);
        }
    }
    return -1;
}

vector<node *> nodesAtDistanceK(node *root, node *n, int k)
{
    // nodes can be present in ancestor as well as subtree

    vector<node *> v = {};
    addSubtreeNodes(n, k, v);
    addAncestorNodes(root, n, k, v);
    return v;
}

int main()
{
    /*
    
    Creating this binary tree
        * * * * * * * * *
        *       1       *    
        *      / \      *
        *     2   3     *
        *    / \ / \    *    
        *   4  5 6  7   *
        *  / \    \     *
        * 10  8     9   *
        * * * * * * * * *

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

    for (node *x : nodesAtDistanceK(root, root->left, 2))
        cout << x->data << ' ';
}
