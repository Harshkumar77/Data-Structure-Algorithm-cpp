#include <iostream>
#include <vector>
#include <algorithm>

// TODO: Add cmts asap

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second <= p2.second;
}

int maxActivity(vector<pair<int, int>> a, int n)
{
    int prevEnd = 0, activity = 0;
    sort(a.begin(), a.end(), comp);

    for (int i = 0; i < n; i++)
        if (a[i].first >= prevEnd)
            activity++, prevEnd = a[i].second;
    return activity;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (pair<int, int> &x : a)
        cin >> x.first >> x.second;
    cout << "Maximum activities can be performed : " << maxActivity(a, n);
    return 0;
}