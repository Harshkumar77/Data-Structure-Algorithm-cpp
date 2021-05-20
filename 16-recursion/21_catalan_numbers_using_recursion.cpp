#include <iostream>
using namespace std;

int NthCatalan(int n)
{
    if (n == 0 or n == 1)
        return 1;
    int x = 0;
    for (int i = 0; i < n; i++)
        x += NthCatalan(i) * NthCatalan(n - i - 1);
    a[n] = x;
    return x;
}

int main()
{
    for (int i = 0; i < 20; i++)
        cout << NthCatalan(i) << '\n';
}