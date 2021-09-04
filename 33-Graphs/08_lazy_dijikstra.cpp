#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

vector<int> shortest_path(vector<vector<edge>> adj, int from)
{
    // shortest path using lazy implementation of dijikstra algorithm
    int n = adj.size();
    vector<int> dist(n, INT16_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // { dist , vertice}
    dist[from] = 0;
    pq.push({0, from});
    while (not pq.empty())
    {
        pair<int, int> top = pq.top();
        if (dist[top.second] < top.first)
        {
            pq.pop();
            continue;
        }
        int j = 0;
        for (edge e : adj[top.second])
        {
            dist[e.to] = min(dist[e.to], dist[top.second] + adj[top.second][j].weight);
            pq.push({dist[e.to], e.to});
            j++;
        }
        pq.pop();
    }

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
    vector<int> dist = shortest_path(adj, 8);
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << " -> " << dist[i] << '\n';
    }
    return 0;
}