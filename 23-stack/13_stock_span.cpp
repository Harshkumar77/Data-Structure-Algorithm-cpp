#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, days;
    cin >> N;
    int a[N];
    for (int &x : a)
        cin >> x;
    stack<pair<int, int>> s;
    for (int i = 0; i < N; i++)
    {
        days = 1;
        while (not s.empty() and s.top().first <= a[i])
        {
            days += s.top().second;
            s.pop();
        }
        s.push(make_pair(a[i], days));
        cout << days << ' ';
    }
}