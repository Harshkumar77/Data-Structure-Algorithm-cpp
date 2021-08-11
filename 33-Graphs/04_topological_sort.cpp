#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/**
 * Topological sort in a graph [iterative way]
 * Intution :
 *  Traversing graph is DFS manner , to cover the branches in Graph
*/
void printQ(queue<int> q)
{
    if (q.empty())
    {
        cout << '\n';
        return;
    }
    cout << q.front() << ' ';
    q.pop();
    printQ(q);
}
void printS(stack<int> s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    printS(s);
    cout << x << ' ';
}
void topologicalSort(vector<vector<int>> adj)
{
    int n = adj.size();
    vector<int> indeg(n, 0);
    for (int i = 1; i < n; i++)
        for (int x : adj[i])
            indeg[x]++;
    queue<int> zi;
    stack<int> wait;
    for (int i = 1; i < n; i++)
        if (indeg[i] == 0)
            zi.push(i);
    while (not zi.empty())
    {
        int x = zi.front();
        for (int i : adj[x])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                wait.push(i);
        }
        cout << x << ' ';
        zi.pop();
        if (not wait.empty())
        {
            zi.push(wait.top());
            wait.pop();
        }
    }
    cout << '\n';
}

int main()
{
    vector<vector<int>> adjl = {
        {},
        {2},
        {3, 4},
        {5},
        {6},
        {6},
        {}};
    vector<vector<int>> adjl2 = {
        {},
        {3},
        {3},
        {4},
        {5, 7},
        {6},
        {7},
        {8},
        {}};
    vector<vector<int>> adjl3 = {
        {},
        {2, 3},
        {3},
        {4},
        {6, 7},
        {1},
        {8},
        {8},
        {},
        {1}};
    topologicalSort(adjl);
    topologicalSort(adjl2);
    topologicalSort(adjl3);
}