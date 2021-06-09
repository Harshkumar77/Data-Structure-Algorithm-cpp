#include <bits/stdc++.h>
using namespace std;
/**
 * Program to find maximaum subarray of size K and sum < x
 * 
 * Time Complexity : O ( N ) N -> size of array
 * Space Complexity : O ( 1 )
*/

/**
 * Algorithm :
 * 
 *      1. Create a window of size K using 2 pointers
 *      2. For each iteration updating the window and checking given condition
*/
void func(int a[], int N, int K, int X)
{
    int l = 1, r = K, finalL, finalR, sum = accumulate(a, a + K, 0), maxSum = INT16_MIN;
    // used aacumulate function to calcute sum of first k elements i.e. 1st window
    if (sum < X)
    {
        finalL = 0, finalR = K - 1;
        maxSum = sum;
    }
    while (r < N)
    {
        sum += a[r] - a[l - 1]; // Updating window
        if (sum < X and sum > maxSum)
        {
            finalL = l, finalR = r;
            maxSum = max(maxSum, sum);
        }
        r++, l++;
    }
    for (int i = finalL; i <= finalR; i++)
        cout << a[i] << ' ';
    cout << '\n';
    cout << "Sum of maximum Subarray of size K and less than X : " << maxSum;
}

int main()
{
    int N, K, X;
    cin >> N >> K >> X;
    int a[N];
    for (int &x : a)
        cin >> x;
    func(a, N, K, X);
}
/*

Input :

5 3 8
3 4 1 2 1

Output :

4 1 2 
Sum of maximum Subarray of size K and less than X : 7

*/