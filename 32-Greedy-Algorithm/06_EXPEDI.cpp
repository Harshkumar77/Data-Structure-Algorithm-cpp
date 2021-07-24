#include <bits/stdc++.h>
using namespace std;

#define int long long
// TODO: Add cmntss u lazy
void solve()
{
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (pair<int, int> &x : v)
        cin >> x.first >> x.second;
    int L, P;
    cin >> L >> P;
    for (pair<int, int> &x : v)
        x.first = L - x.first;
    sort(v.begin(), v.begin() + N);
    int cnt = 0, dis = 0;
    priority_queue<int> pq;
    for (pair<int, int> &x : v)
    {
        if (P >= L)
            break;
        while (P < x.first)
        {
            if (pq.empty())
            {
                cout << -1 << '\n';
                return;
            }
            P += pq.top();
            pq.pop();
            cnt++;
        }
        pq.push(x.second);
    }
    while (not pq.empty() and P < L)
        cnt++, P += pq.top(), pq.pop();
    if (P < L)
    {
        cout << -1 << '\n';
        return;
    }
    cout << cnt << '\n';
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}