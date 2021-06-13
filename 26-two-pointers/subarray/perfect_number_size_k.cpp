#include <bits/stdc++.h>
using namespace std;

/**
 * Program to print maximum perfect numbers present in subarray of size K
 *  
 * Perfect Number -> sum of divisor excluding it is equal to itself
 *                      Example - 6 = 1 + 2 + 3
 * 
 * Time Complexity : O(N) N->Size of array
 * Space Complexity : O(1)
*/

void subarrayLargestPerfectNo(int a[], int N, int K)
{
    for (int i = 0; i < N; i++)
    {
        int sum = 1;
        for (int j = 2; j * j <= a[i]; j++)
            if (a[i] % j == 0)
                sum += j + a[i] / j; // a[i]/j to cover the second divisor
                                     // for ex -> IN 6 , if 2 is first divisor then
                                     // 6/2=3 is second
        if (sum == a[i] and a[i] != 1)
            a[i] = 1;
        else
            a[i] = 0;
    }

    // converting the orignal array into an boolean in which the element is
    // replaced by value that whether it is perfect or not

    int currPerfect = accumulate(a, a + K, 0), maxPerfectNo = currPerfect;
    // our usual sliding window technique
    for (int i = 1, r = i + K - 1; r < N; i++, r++)
    {
        currPerfect += a[r] - a[i - 1];
        maxPerfectNo = max(currPerfect, maxPerfectNo);
    }
    cout << "Maximum perfect number : " << maxPerfectNo << '\n';
}
int main()
{
    int N, K;
    cin >> N >> K;
    int a[N];
    for (int &x : a)
        cin >> x;
    subarrayLargestPerfectNo(a, N, K);
}