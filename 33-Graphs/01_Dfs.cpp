#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;

void print_dfs(vector<vector<int>> adj, int from)
{
    if (visited[from])
        return;
    cout << from << ' ';
    visited[from] = true;
    for (int x : adj[from])
        print_dfs(adj, x);
}

bool find(int key, vector<vector<int>> adj, int from, vector<int> path = {})
{
    if (key == from)
    {
        for (int x : path)
            cout << x << "->";
        cout << key;
        cout << '\n';
        return true;
    }
    if (visited[from])
        return false;
    visited[from] = true;
    path.push_back(from);
    bool isThere = 0;
    for (int x : adj[from])
        find(key, adj, x, path) and (isThere = true);
    return isThere;
}

int main()
{
    vector<vector<int>> adjl = {
        {},
        {2, 3},
        {5},
        {4},
        {},
        {4, 1}};
    visited = vector<bool>(adjl.size(), false);
    print_dfs(adjl, 1);
    cout << '\n';
    visited = vector<bool>(adjl.size(), false);
    print_dfs(adjl, 3);
    cout << '\n';
    visited = vector<bool>(adjl.size(), false);
    print_dfs(adjl, 5);
    cout << '\n';
    visited = vector<bool>(adjl.size(), false);
    cout << find(4, adjl, 1);
    return 0;
}