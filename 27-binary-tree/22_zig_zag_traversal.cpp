/**

Program to traverse binary tree in zig zag order

Time Complexity -> O(N)
Space Complexity -> O(N)


 **/
#include <iostream>
#include <stack>
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
/*
    Intution : Similar to level order traversal
    Algorithm :
        1. Using two stack
        2. Pushing the root in s1
        3. Traversing stack in level order manner by poping the s1 stack
        4. while traversing push the left and right for left to right
            and 
            right and left for right to left 
             of curr node in s2
        5. swaping both the stacks at every traversal
*/
vector<node *> zig_zag_traversal(node *root)
{
    vector<node *> v;
    bool leftToRight = true;
    stack<node *> s1, s2, empty;
    s1.push(root);
    node *temp;
    while (!s1.empty() or !s2.empty())
    {
        while (!s1.empty())
        {
            temp = s1.top();
            v.push_back(temp);
            s1.pop();
            if (leftToRight)
            {
                if (temp->right != NULL)
                    s2.push(temp->right);
                if (temp->left != NULL)
                    s2.push(temp->left);
            }
            else
            {
                if (temp->left != NULL)
                    s2.push(temp->left);
                if (temp->right != NULL)
                    s2.push(temp->right);
            }
        }
        s1 = s2;
        s2 = empty;
        leftToRight = !leftToRight;
    }
    return v;
}
int main()
{
    /*
                    
                    Creating this binary tree
                        * * * * * * * * * *
                        *        1        *    
                        *       / \       *
                        *      2   3      *
                        *     / \ / \     *    
                        *   -4  5 -6  7   *
                        *   / \     \     *
                        * -10  8     9    *
                        * * * * * * * * * *

                    */

    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(-4);
    root->left->left->left = new node(-10);
    root->left->left->right = new node(8);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->right = new node(7);
    root->right->left = new node(-6);
    root->right->left->right = new node(9);

    for (node *y : zig_zag_traversal(root))
        cout << y->data << ' ';
    cout << '\n';
}
