#include <iostream>
#include <vector>

using namespace std;

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
int N = 10;

vector<int> coinChange(int x)
{
    vector<int> change;
    for (int i = N - 1; x > 0 and i >= 0; i--)
    {
        if (x >= coins[i])
        {
            for (int j = 0; j < x / coins[i]; j++)
                change.push_back(coins[i]);
            x = x % coins[i];
        }
    }
    return change;
}

int main()
{
    int x;
    cin >> x;
    for (int t : coinChange(x))
        cout << t << ' ';
}