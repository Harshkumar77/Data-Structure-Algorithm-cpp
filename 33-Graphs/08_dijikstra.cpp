#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
// shortest path using lazy implementation of dijikstra algorithm

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

/**
 * Intution : 
 *      from the from vertice move toward the shortest vertice greedly to find the 
 *      to vertice in shortest distance
 * 
 *      Algorithm is going to cover all the graph so that is the to node is reached 
 *      firstly in longer distance it will be corrected futherly
 */

void shortest_path_distance(vector<vector<edge>> adj, int from, int to)
{
    int n = adj.size();
    vector<int> dist(n, INT16_MAX);
    vector<int> prev(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // { dist , vertice}
    dist[from] = 0;
    pq.push({0, from});
    while (not pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        // The path choosed here is by default going to be longer because
        // a shorter path has been already discoverd paasing through  this node
        if (dist[top.second] < top.first)
            continue;
        int j = 0;
        for (edge e : adj[top.second])
        {
            int newDis = dist[top.second] + adj[top.second][j].weight;
            if (newDis < dist[e.to])
            {
                dist[e.to] = dist[top.second] + adj[top.second][j].weight;
                pq.push({dist[e.to], e.to});
                prev[e.to] = top.second;
            }
            j++;
        }
    }
    if (dist[to] == INT16_MAX)
        cout << to << " in not rechable" << '\n';
    else
    {
        cout << "distance to " << to << " = " << dist[to] << '\n';
        stack<int> path;
        for (int x = prev[to]; x != from; x = prev[x])
            path.push(x);
        cout << from << " -> ";
        while (not path.empty())
            cout << path.top() << " -> ", path.pop();
        cout << to << "\n";
    }
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
    shortest_path_distance(adj, 8, 4);
    shortest_path_distance(adj, 8, 5);
    shortest_path_distance(adj, 8, 1);
    return 0;
}