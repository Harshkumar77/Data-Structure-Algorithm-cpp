#include <iostream>
using namespace std;
/**
 * Program to merge 2 sorted array in constant space
 * 
 * Time Complexity : O(N+M log (N+M))
 * Space Complexity : O(1)
*/

/**
 * Intution : Shell Sort
 * We perform shell sort with an imaginary combination of two arrays
*/
void merge(int a[], int b[], int X, int Y)
{
    int w = (X + Y);
    while (w > 1)
    {
        w = w / 2 + w % 2;
        for (int i = 0; i + w < X + Y; i++)
            if (i + w < X and a[i] > a[i + w])
                swap(a[i], a[i + w]);
            else if (i + w >= X and i < X and a[i] > b[i + w - X])
                swap(a[i], b[i + w - X]);
            else if (i >= X and b[i - X] > b[i + w - X])
                swap(b[i - X], b[i + w - X]);
    }
}
int main()
{
    int X, Y;
    cin >> X >> Y;
    int a[X], b[Y];
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    merge(a, b, X, Y);
    for (int x : a)
        cout << x << ' ';
    for (int x : b)
        cout << x << ' ';
}