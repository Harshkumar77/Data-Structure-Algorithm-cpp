#include <iostream>
using namespace std;

const int N = 9;

bool isSafe(int grid[N][N], int x, int y, int val)
{
    for (int i = 0; i < N; i++)
        if (grid[x][i] == val)
            return false;
    for (int i = 0; i < N; i++)
        if (grid[i][y] == val)
            return false;
    int a = x - x % 3, b = y - y % 3;
    for (int i = a; i < a + 3; i++)
        for (int j = b; j < b + 3; j++)
            if (grid[i][j] == val)
                return false;
    return true;
}

bool sudoku_solver(int grid[N][N], int x = 0, int y = 0)
{
    if (x == N && y == N - 1)
        return true;
    if (x == N)
        y++, x = 0;

    if (grid[x][y] != 0)
        return sudoku_solver(grid, x + 1, y);

    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, x, y, num))
        {
            grid[x][y] = num;                  // trying the branch
            if (sudoku_solver(grid, x + 1, y)) // checking if the branch is final answer
                return true;
        }
        grid[x][y] = 0; // back tracking
    }
    return false;
}

int main()
{
    int grid[N][N] =
        {{3, 0, 6, 5, 0, 8, 4, 0, 0},
         {5, 2, 0, 0, 0, 0, 0, 0, 0},
         {0, 8, 7, 0, 0, 0, 0, 3, 1},
         {0, 0, 3, 0, 1, 0, 0, 8, 0},
         {9, 0, 0, 8, 6, 3, 0, 0, 5},
         {0, 5, 0, 0, 9, 0, 6, 0, 0},
         {1, 3, 0, 0, 0, 0, 2, 5, 0},
         {0, 0, 0, 0, 0, 0, 0, 7, 4},
         {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    sudoku_solver(grid);
    for (int i = 0; i < N; i++, cout << '\n')
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << ' ';
}