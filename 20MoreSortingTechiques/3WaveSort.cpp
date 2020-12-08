#include <iostream>
using namespace std;

void waveSort(int a[], int n)
{
    for (int i = 1; i < n; i += 2)
    {
        if (a[i - 1] > a[i])
            swap(a[i - 1], a[i]);
        if (a[i + 1] > a[i] and i < n - 1)
            swap(a[i + 1], a[i]);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int &i : a)
        cin >> i;
    waveSort(a, n);
    for (int &i : a)
        cout << i << " ";
}