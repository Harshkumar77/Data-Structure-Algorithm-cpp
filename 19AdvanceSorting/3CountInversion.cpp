#include <iostream>
using namespace std;

int merge(int arr[], int l, int r, int mid)
{
    int count = 0;
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
        if (le[sl] <= ri[sr])
            arr[ap++] = le[sl++];
        else
        {
            count += n1 - ap;
            arr[ap++] = ri[sr++];
        }
    }
    while (sl < n1)
        arr[ap++] = le[sl++];
    while (sr < n2)
        arr[ap++] = ri[sr++];
    return count;
}

int mergeSort(int arr[], int l, int r)
{
    int count = 0;
    if (l == r)
        return 0;
    int mid = l / 2 + r / 2;
    count += mergeSort(arr, l, mid);
    count += mergeSort(arr, mid + 1, r);
    count += merge(arr, l, r, mid);
    return count;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &x : a)
        cin >> x;
    cout << mergeSort(a, 0, n - 1);
}