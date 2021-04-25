#include <iostream>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int a[N];
    for (int &x : a)
        cin >> x;
    int j = 0, ans = -1, zerocnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] == 0)
            zerocnt++;
        while (zerocnt > K)
        {
            if (a[j] == 0)
                zerocnt--;
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans;
    return 0;
}