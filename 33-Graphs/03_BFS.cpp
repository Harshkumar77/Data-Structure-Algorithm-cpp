#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> added;

void print_BFS(int from, vector<vector<int>> adj)
{
    queue<int> q;
    q.push(from);
    added[from] = true;
    while (not q.empty())
    {
        for (int x : adj[q.front()])
            if (not added[x])
                q.push(x), added[x] = true;
        cout << q.front() << ' ';
        q.pop();
    }
}

int main()
{
    vector<vector<int>> adjl = {
        {},
        {2, 3, 6},
        {},
        {6},
        {},
        {},
        {5, 7},
        {}};
    added = vector<bool>(adjl.size() - 1, 0);
    print_BFS(1, adjl);
    return 0;
}