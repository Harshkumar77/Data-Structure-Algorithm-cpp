#include <iostream>
#include <map>
#include <vector>

// Please see backtracking aproach before this to start

using namespace std;

const int N = 9;

bool moveAndTry(int x, int y, vector<vector<int>> &v, map<pair<int, int>, map<int, bool>> &g, vector<map<int, bool>> &c, vector<map<int, bool>> &r)
{
    if (x == N && y == N - 1)
        return true; // Sudoku traversal complete
    if (x == N)
        y++, x = 0; // column travesal complete and changed row for further traversal

    if (v[x][y] != 0)
        return moveAndTry(x + 1, y, v, g, c, r);
    for (int i = 1; i <= N; i++)
    {
        if (!r[x][i] and
            !c[y][i] and
            !g[{x / 3, y / 3}][i])
        {
            r[x][i] = true; // trying this branch
            c[y][i] = true;
            g[{x / 3, y / 3}][i] = true;
            v[x][y] = i;
            if (moveAndTry(x + 1, y, v, g, c, r))
                return true;
            v[x][y] = 0; // backtracking from the branch
            r[x][i] = false;
            c[y][i] = false;
            g[{x / 3, y / 3}][i] = false;
        }
    }
    return false;
}

void solveSudoku(vector<vector<int>> &v)
{
    map<pair<int, int>, map<int, bool>> g; // map for checking if number is present in mini grid
    // left top coordinates of mini grid ->  number -> present or not
    vector<map<int, bool>> c(N); // created vector for checking if number present in column
    // column number -> value to check -> present or not
    vector<map<int, bool>> r(N); // created vector for checking if number present in row
    // row number -> value to check -> present or not

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (v[i][j] != 0)
            {
                g[{i / 3, j / 3}][v[i][j]] = true;
                c[j][v[i][j]] = true;
                r[i][v[i][j]] = true;
            }
    // Giving all the maps data to start
    moveAndTry(0, 0, v, g, c, r);
}

int main()
{
    vector<vector<int>> v =
        {
            {3, 0, 1, 0, 0, 0, 7, 5, 0},
            {0, 7, 0, 6, 3, 4, 0, 0, 0},
            {8, 0, 0, 0, 0, 7, 0, 2, 0},
            {1, 0, 4, 9, 0, 3, 0, 0, 2},
            {0, 3, 7, 0, 0, 0, 0, 9, 8},
            {9, 0, 2, 5, 0, 0, 0, 0, 1},
            {4, 1, 3, 0, 9, 0, 2, 6, 0},
            {0, 0, 8, 0, 0, 0, 0, 0, 7},
            {7, 0, 0, 0, 6, 2, 8, 0, 4},
        };
    solveSudoku(v);
    for (auto x : v)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}
