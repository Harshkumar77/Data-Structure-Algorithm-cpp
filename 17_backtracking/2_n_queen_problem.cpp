#include <iostream>
using namespace std;

isSafe(int **arr , int x , int y , int n)
{
    for (int i = 0; i < x; i++)
    {
        if (arr[i][y]==1)
        {
            return false;
        }
    }
    for (int i = 0; i < y; i++)
    {
        if (arr[x][i]==1)
        {
            return false;
        }
    }
    int p1 = x , p2 = y ;
    while (p1>=0 and p2>=0)
    {
        if (a[p1][p2]==1)
        {
            return false;
        }
        p1--;
        p2--;   
    }
    while (p1>=0 and p2<n)
    {
        if (a[p1][p2]==1)
        {
            return false;
        }
        p1--;
        p2++;
    }
    return true;
}

bool nQueen(int** arr , int x , int y , int n)
{
    if (/* condition */)
    {
        /* code */
    }
    
}