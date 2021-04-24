#include <iostream>
using namespace std;

bool isSafe(int **a, int x, int y, int n)
{
    if (a[x][y] == 1 and x < n and y < n)
    {
        return true;
    }
    return false;
}

bool ratInMaze(int **a, int x, int y, int n, int **sol)
{
    if ((x == (n - 1)) and (y == (n - 1)))
    {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(a, x, y, n))
    {
        sol[x][y] = 1;
        if (ratInMaze(a, x + 1, y, n, sol))
        {
            return true;
        }
        if (ratInMaze(a, x, y + 1, n, sol))
        {
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **maze = new int *[n];
    int **path = new int *[n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[n];
        path[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
            path[i][j] = 0;
        }
    }
    path[0][0] = 1;
    (ratInMaze(maze, 0, 0, n, path));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << path[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}