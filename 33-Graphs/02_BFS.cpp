#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Traverse graph is BFS manner from an adjacency list
*/

void BFS(vector<vector<int>> adjl, int top)
{
    bool vis[1000] = {};
    queue<int> q;
    q.push(top);
    vis[top] = true;
    while (not q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int x : adjl[cur])
            if (not vis[x])
            {
                q.push(x);
                vis[x] = true;
            }
        cout << cur << ' ';
    }
    cout << '\n';
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
    BFS(adjl, 1);
}