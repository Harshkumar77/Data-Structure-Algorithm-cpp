#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int &x : a)
        cin >> x;
    deque<int> d;
    d.push_back(0);
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        if (a[i] > a[d.front()])
            d.pop_front(), d.push_back(i);
    }
    ans.push_back(a[d.front()]);
    for (int i = k; i < n; i++)
    {
        if (i - k == d.front())
            d.pop_front();
        while (!d.empty() and a[d.back()] < a[i])
            d.pop_back();
        d.push_back(i);
        ans.push_back(a[d.front()]);
    }
    for (int x : ans)
        cout << x << ' ';
}