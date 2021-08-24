#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &toposortorder)
{
    // if (visited[node])
    //     return;
    for (int x : adj[node])
        if (not visited[x])
            visited[x] = true, dfs(x, adj, visited, toposortorder);
    toposortorder.push_back(node);
}

vector<int> toposort(vector<vector<int>> &adj)
{
    vector<int> toposortorder;
    vector<bool> visited(adj.size(), false);
    for (int i = 1; i < adj.size(); i++)
        if (not visited[i])
        {
            // cout << 'i' << ' ' << i << ' ';
            visited[i] = true;
            dfs(i, adj, visited, toposortorder);
                }
    reverse(toposortorder.begin(), toposortorder.end());
    return toposortorder;
}

int main()
{
    vector<vector<int>> adj = {
        {},
        {2, 6},
        {4, 5},
        {2},
        {5},
        {},
        {},
        {6, 9},
        {7},
        {}};
    vector<int> ans = toposort(adj);
    for (int x : ans)
        cout << x << ' ';
}