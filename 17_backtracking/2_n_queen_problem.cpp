#include <iostream>
using namespace std;

isSafe(int **arr, int x, int y, int n)
{
    for (int i = 0; i < x; i++)
    {
        if (arr[i][y] == 1)
        {
            return false;
        }
    }
    for (int i = 0; i < y; i++)
    {
        if (arr[x][i] == 1)
        {
            return false;
        }
    }
    int p1 = x, p2 = y;
    while (p1 >= 0 and p2 >= 0)
    {
        if (arr[p1][p2] == 1)
        {
            return false;
        }
        p1--;
        p2--;
    }
    p1 = x, p2 = y;
    while (p1 >= 0 and p2 < n)
    {
        if (arr[p1][p2] == 1)
        {
            return false;
        }
        p1--;
        p2++;
    }
    return true;
}

bool nQueen(int **arr, int x, int n)
{
    if (x == n)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (isSafe(arr, x, i, n))
        {
            arr[x][i] = 1;
            if (nQueen(arr, x + 1, n))
            {
                return true;
            }
            arr[x][i] = 0; //backtracking
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    nQueen(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}