#include <iostream>
#include <climits>
using namespace std;

void countSort(int a[], int n)
{
    int b[n], mx = a[0];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
        mx = max(a[i], mx);
    }
    int cnt[mx+1]={};
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }
    
    for (int i = 1; i <= mx; i++)
    {
        cnt[i]+=cnt[i-1];
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        b[--cnt[a[i]]]=a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i]=b[i];
    }
    
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    countSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"  ";
    }
    
}