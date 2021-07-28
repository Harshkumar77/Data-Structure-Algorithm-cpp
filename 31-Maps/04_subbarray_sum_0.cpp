#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * Program to find all the subarray with sum 0
 * TC - O ( N )
 * SC - O ( unique(N) )
*/
void printSubarraySum0(int a[], int N)
{
    // brute force helper function to find all the possible subarray with sum 0
    int sarr = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        string ar = "";
        for (int j = i; j < N; j++)
        {
            sum += a[j];
            ar.append(to_string(a[j]) + " ");
            if (sum == 0)
                cout << ar << '\n', sarr++;
        }
    }
    cout << "Number of subarray of sum 0 : " << sarr << '\n';
}

/**
 * Algorithm : 
 * 1. Storing all the prefix sum with their frequency
 * 2. If prefix sum is 0 it means the subbarray from start to that point
 *      sums to 0
 * 3. If a prefix sum is same at 2 points it means the subbarray b/w two points
 *      sums to 0
 * 4. So if prefix sum is same at n points , then the number of subbarray that 
 *      sums 0 would be NC2 [permutation] 
*/

int subarraySum0(int a[], int N)
{
    unordered_map<int, int> fx;
    int cnt = 0, prefixSum = 0;
    for (int i = 0; i < N; i++)
        prefixSum += a[i], fx[prefixSum]++;
    cnt += fx[0];
    for (unordered_map<int, int>::iterator i = fx.begin(); i != fx.end(); i++)
    {
        int freq = (*i).second;
        cnt += (freq) * (freq - 1) / 2;
    }
    return cnt;
}

int main()
{
    int N;
    cin >> N;
    int a[N];
    for (int &x : a)
        cin >> x;
    printSubarraySum0(a, N);
    cout << subarraySum0(a, N);
}