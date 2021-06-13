/***
 * Program to print all the palindromic subarray of size K.
 * 
 * Time complexity : O (N*K) => N=Size of array K=size of subarray
 * Space complexity : O (1)
 * 
 */
#include <iostream>
using namespace std;
/*
    Intution :
    We create an sliding window of size K and check traverse the array
*/
void palindrome(int a[], int N, int K)
{
    bool pal = 0;
    for (int i = 0; i + K <= N; i++)
    {
        pal = 1;
        for (int j = i; j <= K / 2; j++)
        {
            if (a[j] != a[i + K - j - 1])
            {
                pal = 0;
                break;
            }
        }
        if (pal)
        {
            for (int j = i; j < i + K; j++)
                cout << a[j] << ' ';
            cout << '\n';
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    int a[N];
    for (int &x : a)
        cin >> x;
    palindrome(a, N, K);
}