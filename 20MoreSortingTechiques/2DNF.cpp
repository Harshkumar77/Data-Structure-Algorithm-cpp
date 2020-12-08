#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int &i : a)
        cin >> i;
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid < high)
    {
        if (a[mid] == 0)
            swap(a[mid++], a[low++]);
        else if (a[mid] == 1)
            mid++;
        else
            swap(a[mid++], a[high--]);
    }
    for (int x : a)
        cout << x << " ";
}