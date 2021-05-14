/**

Program to find lowest common ancestor in two nodes of a binary tree 

Time Complexity  -> O(N)
Space Complexity -> O(MAX(distance(node a) , distance(node b)))

Space complexity here is caused to the path vector created

Simpler code with better space complexity is given in 
https://github.com/Harshkumar77/Data-Structure-Algorithm-cpp/blob/main/27-binary-tree/18_shortest_distance_bw_2_nodes.cpp

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

bool getPath(node *toFind, node *root, vector<node *> &path)
{
    /*

    Backtracking solution to check and find path of a node from node

    */
    if (root == NULL)
        return false;
    path.push_back(root);
    if (root == toFind)
    {
        return true;
    }
    vector<node *> v = path; //Path being pushed in this vector
    if (root->left != NULL and getPath(toFind, root->left, path))
    {
        return true;
    }
    path = v;
    // backtracking to the orignal path
    if (root->right != NULL and getPath(toFind, root->right, path))
    {
        return true;
    }
    path = v;
    // backtracking to the orignal path

    return false;
}

node *LowestCommonAncestor(node *root, node *a, node *b)
{
    vector<node *> p1, p2;
    if (!getPath(a, root, p1) or !getPath(b, root, p2))
    {
        cout << a->data << " or " << b->data << " is not present in the given BT\n";
        return NULL;
    }
    for (int i = 0; i < min(p1.size(), p2.size()); i++)
    {
        if (p1[i] != p2[i])
            return p1[i - 1];
    }
    if (p1.size() < p2.size())
        return p1[p1.size() - 1];
    return p2[p2.size() - 1];
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

    cout << LowestCommonAncestor(root, root->right->left->right, root->left->right)->data;
}