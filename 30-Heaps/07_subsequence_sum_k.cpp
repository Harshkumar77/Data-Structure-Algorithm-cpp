#include <iostream>
#include <queue>
using namespace std;

/**
 * Program to find the smallest lenght of the subsequence of sum >= K
 * 
 * TC : O ( N log N)
 * SC : O ( N )
 * 
 * NOTE : The same can be done with an array in O(1) Space :-)
*/

/**
 * Intution : 
 * The subsequence with least lenght must contain the greatest elements of array
*/
int ans(int a[], int N, int K)
{
    priority_queue<int> p;
    for (int i = 0; i < N; i++)
        p.push(a[i]);
    int cnt = 0, sum = 0;
    while (not p.empty() and sum < K)
    {
        sum += p.top();
        p.pop();
        cnt++;
    }
    if (sum < K)
        return 0;
    return cnt;
}

int main()
{
    int N, K;
    cin >> N >> K;
    int a[N];
    for (int &x : a)
        cin >> x;
    cout << ans(a, N, K);
    return 0;
}