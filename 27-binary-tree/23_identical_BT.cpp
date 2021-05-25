/**

Program to check if two binary trees are equal (not by memory adress)

Time Complexity -> O(N)
Space Complexity -> O(N)


 **/
#include <iostream>

using namespace std;

#define varName(x) #x

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
        left = a;
        right = b;
        data = val;
    }
};

bool areEqual(node *a, node *b)
{
    // Checking every node data with other node data correspondingly
    if (a == NULL and b == NULL)
        return true; // base case both BT end means equal in lenght
    if (a == NULL or b == NULL)
        return false; // if only one of them is null means there lenght are not equal
    return a->data == b->data and
           areEqual(a->left, b->left) and
           areEqual(a->right, b->right);
}

int main()
{
    /**
 *                 Creating these trees
 *                        1
 *                       / \ 
 *                      2   3 
 *                        1
 *                       / \ 
 *                      2   3 
 *                        5
 *                       / \ 
 *                      4   6
*/

    node *a = new node(1, new node(2), new node(3));
    node *b = new node(1, new node(2), new node(3));
    node *c = new node(5, new node(4), new node(6));

    cout << varName(a);
    areEqual(a, b) ? cout << " is equal to " : cout << " is not equal to ";
    cout << varName(b) << '\n';

    cout << varName(a);
    areEqual(a, c) ? cout << " is equal to " : cout << " is not equal to ";
    cout << varName(c) << '\n';
}
