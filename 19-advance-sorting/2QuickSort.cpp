#include <iostream>
using namespace std;

int partion(int a[], int l, int r)
{
    int i = l - 1;
    int pivot = a[r];
    for (int j = l; j < r; j++)
    {
        if (a[j] < pivot)
        {
            swap(a[++i], a[j]);
        }
    }
    swap(a[++i], a[r]);
    return i ;
}

void quickSort(int a[], int l, int r)
{
    if (l == r)
        return;
    int p = partion(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int &i : a)
        cin >> i;
    quickSort(a, 0, n - 1);
    for (int &i : a)
        cout << i << " ";
    cout << '\n';
}