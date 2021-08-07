#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Traverse graph is DFS manner from an adjacency list
*/

void preorder_DFS(vector<vector<int>> &adjl, int top)
{
    static bool vis[1000] = {};
    // preorder : current node then its connected node
    vis[top] = true;
    cout << top << ' ';
    for (int x : adjl[top])
        if (!vis[x])
            preorder_DFS(adjl, x);
}

void postorder_DFS(vector<vector<int>> &adjl, int top)
{
    static bool vi[1000] = {};
    // postorder : connected node then current node
    vi[top] = true;
    for (int x : adjl[top])
        if (!vi[x])
            postorder_DFS(adjl, x);
    cout << top << ' ';
}

int main()
{
    vector<vector<int>> adjl = {
        {},
        {2, 3},
        {1, 4},
        {1, 5},

        {2, 5, 6},
        {3, 4, 6},
        {4, 5, 7},
        {6}};
    preorder_DFS(adjl, 1);
    cout << '\n';
    postorder_DFS(adjl, 1);
    cout << '\n';
}