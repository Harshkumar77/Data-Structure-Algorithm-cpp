/**
 * Program to find size of largest BST in a BT 
 * Time Complexity : O(n)
 * Space Complexity : O(n)
*/

#include <iostream>
#include <climits>

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

struct info
{
    bool isBST;
    int minimum;
    int maximum;
    int size;
    int sizeLargestBST;

    info(bool a, int b, int c, int d, int e)
    {
        isBST = a;
        minimum = b;
        maximum = c;
        size = d;
        sizeLargestBST = e;
    }
};

/**
 * Creating a info structure to store the properties for each node , so that we dont have to traverse the 
 * whole tree n^2 time for finding size again and again
 * 
 * comparing info of left and right subtree to find info of current node 
 *  
*/

info largestBST(node *x)
{
    if (x == NULL)
        return info(true, INT_MAX, INT_MIN, 0, 0);
    info l = largestBST(x->left);
    info r = largestBST(x->right);
    bool isBST = l.isBST and r.isBST and l.maximum < x->data and r.minimum > x->data;
    int size;
    size = isBST ? l.size + r.size + 1 : 0;
    return info(isBST, min(x->data, min(l.minimum, r.minimum)), max(x->data, max(l.maximum, r.maximum)), size,
                max(size, max(l.sizeLargestBST, r.sizeLargestBST)));
}
int main()
{

    /*
    *         Creating this BT
    *               _-1_
    *              /   \__
    *            _3_      8
    *           /   \    / \
    *          1     5  7   9
    *           \    /       
    *            2  4
    */
    node *root1 = new node(-1);
    root1->left = new node(3, new node(1, NULL, new node(2)), new node(5, new node(4), NULL));
    root1->right = new node(8, new node(7), new node(9));

    cout << largestBST(root1).sizeLargestBST;
}