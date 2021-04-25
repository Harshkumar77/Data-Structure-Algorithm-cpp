#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int a[300];
    for (int &x : a)
        x = -1;
    int start = -1, ans = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (a[s[i]] != -1)
        {
            start = a[s[i]];
        }
        ans = max(ans, i - start);
        a[s[i]] = i;
    }
    cout << ans;
}