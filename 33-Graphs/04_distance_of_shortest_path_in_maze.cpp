#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist = 0;
int x, y, dx, dy;
int m, n;
int node_left_in_layer = 1, node_in_next_layer = 0;
vector<vector<char>> maze;
vector<vector<bool>> added;
queue<int> X;
queue<int> Y;
#define deb(x) cout << #x << '=' << x << '\n';
int xv[] = {0, 1, -1, 0};
int yv[] = {1, 0, 0, -1};

void visit_neighbour()
{
    for (int i = 0; i < 4; i++)
    {
        int vx = X.front() + xv[i];
        int vy = Y.front() + yv[i];
        if (vx >= m or vx < 0 or vy >= n or vy < 0)
            continue;
        if ((maze[vx][vy] == '#') or (added[vx][vy] == true))
            continue;
        node_in_next_layer++;
        X.push(vx), Y.push(vy);
        added[vx][vy] = true;
    }
}

int distance_shortest_path()
{
    X.push(x);
    Y.push(y);
    added[x][y] = true;
    if (x == dx and y == dy)
        return dist;
    while (not X.empty())
    {
        if (X.front() == dx and Y.front() == dy)
            return dist;
        visit_neighbour();
        node_left_in_layer--;
        X.pop(), Y.pop();
        if (node_left_in_layer == 0)
            node_left_in_layer = node_in_next_layer, node_in_next_layer = 0, dist++;
    }
    return 0;
}

int main()
{
    cin >> m >> n;
    maze = vector<vector<char>>(m, vector<char>(n));
    /*
        # -> obstacle 
        _ -> empty block
    */
    added = vector<vector<bool>>(m, vector<bool>(n, false));
    cin >> x >> y >> dx >> dy;
    for (auto &c : maze)
        for (auto &cc : c)
            cin >> cc;
    cout << distance_shortest_path() << '\n';
    return 0;
}