#include <iostream>
using namespace std;

int countPath(int x, int y, int n)
{
    if (x == n - 1 and y == n - 1)
    {
        return 1;
    }
    else if (x >= n or y >= n)
    {
        return 0;
    }
    return countPath(x + 1, y, n) + countPath(x, y + 1, n);
}

int main()
{
    int x, y, n;
    cin >> x >> y >> n;
    cout<<countPath(x, y, n);
    return 0;
}