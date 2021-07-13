#include <iostream>
using namespace std;

int knapsack(int value[], int weight[], int W, int n)
{
    if (n == 0 or W == 0)
    {
        return 0;
    }

    if (W - weight[n - 1] < 0)
    {
        return knapsack(value, weight, W, n - 1);
    }

    return max(knapsack(value, weight, W, n - 1), knapsack(value, weight, W - weight[n - 1], n - 1) + value[n - 1]);
}

int main()
{
    int size, wi;
    cin >> size >> wi;
    int v[size], w[size];
    for (int &i : v)
        cin >> i;
    for (int &i : w)
        cin >> i;
    cout << knapsack(v, w, wi, size);
}