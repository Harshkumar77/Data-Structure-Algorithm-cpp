#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define deb(a) cout << #a << '=' << a << ' ';

class edge
{
public:
    int to;
    int weight;
    edge(int to, int weight)
    {
        this->to = to;
        this->weight = weight;
    }
};

void dfs(int node, vector<vector<edge>> &adj, vector<bool> &visited, vector<int> &toposortorder)
{
    for (edge x : adj[node])
        if (not visited[x.to])
            visited[x.to] = true, dfs(x.to, adj, visited, toposortorder);
    toposortorder.push_back(node);
}
vector<int> toposort(vector<vector<edge>> &adj)
{
    vector<int> toposortorder;
    vector<bool> visited(adj.size(), false);
    for (int i = 1; i < adj.size(); i++)
        if (not visited[i])
        {
            visited[i] = true;
            dfs(i, adj, visited, toposortorder);
        }
    reverse(toposortorder.begin(), toposortorder.end());
    return toposortorder;
}
vector<int> longest_path(vector<vector<edge>> adj, int from)
{
    int n = adj.size();
    vector<int> tops = toposort(adj);
    for (vector<edge> &v : adj)
        for (edge &x : v)
            x.weight = -1 * (x.weight);
    vector<int> dist(n, INT16_MAX);
    for (int x : tops)
        if (x == from)
        {
            dist[x] = 0;
            break;
        }
    for (int x : tops)
    {
        int j = 0;
        for (edge y : adj[x])
        {
            dist[y.to] = min(dist[y.to], dist[x] + adj[x][j].weight);
            j++;
        }
    }
    for (int &x : dist)
        x = -1 * x;
    return dist;
}
int main()
{
    vector<vector<edge>> adj = {
        {},
        {edge(2, 2), edge(6, 5)},
        {edge(4, 3), edge(5, 4)},
        {edge(2, 1)},
        {edge(5, 2)},
        {},
        {},
        {edge(6, 1), edge(9, 3)},
        {edge(7, 1), edge(3, 3)},
        {}};
    vector<int> dist = longest_path(adj, 8);
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << " -> " << dist[i] << '\n';
    }
    return 0;
}