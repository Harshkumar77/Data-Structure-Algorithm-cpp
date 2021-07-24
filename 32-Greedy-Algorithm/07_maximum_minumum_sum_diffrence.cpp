#include <bits/stdc++.h>
using namespace std;
// TODO: so add cmnts chtmrike
int maxSum(int a[], int n)
{
    sort(a, a + n);
    return abs(accumulate(a + n / 2, a + n, 0) - accumulate(a, a + n / 2, 0));
}

int minSum(int a[], int n)
{
    sort(a, a + n);
    int sumOdd = 0, sumEven = 0;
    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            sumEven += a[i];
        else
            sumOdd += a[i];
    return abs(sumOdd - sumEven);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    if (n % 2 != 0)
    {
        cout << "NP" << '\n';
        return 0;
    }
    cout << maxSum(a, n) << '\n'
         << minSum(a, n) << '\n';
    return 0;
}