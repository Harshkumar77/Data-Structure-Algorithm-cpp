#include <iostream>
#include <map>
#include <vector>
/**
 * Program to print binary tree in vertical order
 * TC - O ( N log N ) : N - number of nodes
 * SC - O ( N )
*/

using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int data)
    {
        this->data = data;
        left = NULL, right = NULL;
    }
    node(int data, node *left, node *right)
    {
        this->data = data;
        this->left = left, this->right = right;
    }
};
/**
 * Intution :
 * Storing all the nodes according to the distance from the root
 * The nodes in sorted distance sequence will give the vertical order of binary 
 * tree
*/
map<int, vector<int>> VerticalOrder(node *root, int dist = 0)
{
    static map<int, vector<int>> m;
    if (root == NULL)
        return m;
    m[dist].push_back(root->data);
    VerticalOrder(root->left, dist - 1);
    VerticalOrder(root->right, dist + 1);
    return m;
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

    for (pair<int, vector<int>> p : VerticalOrder(root))
    {
        for (int x : p.second)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}