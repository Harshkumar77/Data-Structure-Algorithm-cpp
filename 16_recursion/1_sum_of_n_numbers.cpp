#include <iostream>
using namespace std;

int sumtill(int n)
{
    if (n == 0)
        return 0;
    return n + sumtill(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << sumtill(n);
    return 0;
}