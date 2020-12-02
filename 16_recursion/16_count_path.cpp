#include <iostream>
using namespace std;

int countWays(int start, int end)
{
    if (start == end)
    {
        return 1;
    }
    else if (start > end)
    {
        return 0;
    }
    int count = 0;
    for (int i = 1; i < end + 1; i++)
    {
        count += countWays(start + i, end);
    }
    return count;
}

int main()
{
    int start, end;
    cin >> start >> end;
    cout << countWays(start, end);
    return 0;
}