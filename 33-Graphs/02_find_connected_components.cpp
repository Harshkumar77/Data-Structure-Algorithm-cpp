#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;

void dfs(vector<vector<int>> adj, int from)
{
    if (visited[from])
        return;
    cout << from << ' ';
    visited[from] = true;
    for (int x : adj[from])
        dfs(adj, x);
}

int print_components(vector<vector<int>> adj)
{
    int count = 0;
    for (int i = 1; i < adj.size(); i++)
    {
        if (not visited[i])
        {
            count++;
            dfs(adj, i);
            cout << '\n';
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> adjl = {
        {},
        {2, 3},
        {5},
        {4},
        {},
        {4, 1},
        {7, 8},
        {8},
        {},
        {}};
    visited = vector<bool>(adjl.size() - 1, false);
    cout << print_components(adjl) << '\n';
    return 0;
}