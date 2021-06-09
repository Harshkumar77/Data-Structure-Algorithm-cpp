#include <bits/stdc++.h>
using namespace std;
/***
 * Program to find an element in sorted and rotated array
 * 
 * Time Complexity : O ( log N ) N-> Size of array
 * 
 * Space Complexity : O ( 1 )
 * 
 */
int binarySearch(int a[], int key, int l, int r)
{
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
/**
 * Algorithm :
 *      1. Using binary search to find the pivot
 *      2. Binary searching left side or right side for the key
*/
int search(int a[], int N, int key)
{

    int l = 0, r = N - 1, mid, pivot = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mid != N - 1 and a[mid] > a[mid + 1])
        {
            pivot = mid;
            break;
        }
        else if (mid != 0 and a[mid] < a[mid - 1])
        {
            pivot = mid - 1;
            break;
        }
        else if (a[mid] > a[r])
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (pivot == -1)
        return binarySearch(a, key, 0, N - 1);
    if (a[pivot] == key)
        return pivot;
    int ans = binarySearch(a, key, 0, pivot);
    if (ans == -1)
        ans = binarySearch(a, key, pivot + 1, N - 1);
    return ans;
}

int main()
{
    int N, key;
    cin >> N >> key;
    int a[N];
    for (int &x : a)
        cin >> x;
    printf("Index is : %d", search(a, N, key));
}
/*
Input :

5 4
4 5 1 2 3

Output :

Index is : 0

*/