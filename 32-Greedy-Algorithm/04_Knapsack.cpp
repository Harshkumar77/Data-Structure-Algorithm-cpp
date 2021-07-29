#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return p2.first / p2.second <= p1.first / p1.second;
}

int knapsack(vector<pair<int, int>> v, int w)
{
    int value = 0;
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size() and w > 0; i++)
        if (v[i].second <= w)
            value += v[i].first, w -= v[i].second;
    return value;
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> v(n);
    // value weight
    for (pair<int, int> &p : v)
        cin >> p.first >> p.second;
    cout << knapsack(v, w);
}
