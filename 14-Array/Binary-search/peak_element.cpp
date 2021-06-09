#include <iostream>
using namespace std;
/**
 * Program to find the peak in an array
 * EX - 1 2 3 2
 * Here 3 is the peak element
 * 
 * Time Complexity : O ( log N ) N -> Size of array
 * Space Complexity : O ( 1 )
 * 
 */
int peak(int a[], int N)
{
    int l = 0, mid = -1, r = N - 1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mid != 0 and mid != N - 1 and a[mid] > a[mid - 1] and a[mid] > a[mid + 1])
            return mid;
        else if (mid != N - 1 and a[mid] > a[mid + 1])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return mid; // It will return the N-1 incase array
                // is sorted and 0 incase array
                // is reversed sorted
}

int main()
{
    int N;
    cin >> N;
    int a[N];
    for (int &x : a)
        cin >> x;
    cout << peak(a, N);
}
/*

Input :

4
4 3 2 1

Output :

0

*/