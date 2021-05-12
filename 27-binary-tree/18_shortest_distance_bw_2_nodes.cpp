/**

Program to find lowest common ancestor in two nodes of a binary tree 

Time Complexity -> O(N)
Space Complexity -> O(1)

Simpler code with same complexity is given in 


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
node *LowestCommonAncestor(node *root, node *a, node *b)
{
}

int main()
{
    /*
    
    Creating this binary tree
    
        1
       / \
      2   3
     / \ / 
    4  5 6  
    
    */

    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    node *a = root->left->left;
    root->left->right = new node(5);
    node *b = root->left->right;
    root->right = new node(3);
    root->right->left = new node(6);

    cout << LowestCommonAncestor(root, a, b)->data;
}
