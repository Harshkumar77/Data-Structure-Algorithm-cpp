#include <iostream>
using namespace std;

void merge(int arr[], int l, int r, int mid)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int le[n1], ri[n2];
    for (int i = 0; i < n1; i++)
    {
        le[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        ri[i] = arr[mid + 1 + i];
    }
    int sl = 0, sr = 0, ap = l;
    while (sl < n1 and sr < n2)
    {
        if (le[sl] < ri[sr])
            arr[ap++] = le[sl++];
        else
            arr[ap++] = ri[sr++];
    }
    while (sl < n1)
        arr[ap++] = le[sl++];
    while (sr < n2)
        arr[ap++] = ri[sr++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l == r)
        return;
    int mid = l / 2 + r / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, r, mid);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &x : a)
        cin >> x;
    mergeSort(a, 0, n - 1);
    for (auto &x : a)
        cout << x << " ";
}