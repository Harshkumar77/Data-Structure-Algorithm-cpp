#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Program to find maximum minimum distance , while selecting k elements from given array
 * 
 * Time complexity :  O ( N log n) N = size_of_array n = maximum_of_array
 * 
 * Space complexity : O ( 1 )
*/

using namespace std;

//                              Brute force helper function

void printKConsecutiveSubset(int a[], int N, int K, int z = 0, vector<int> v = {})
{
    if (N - z < K)
        return;
    if (K == 0)
    {
        for (int x : v)
            cout << x << ' ';
        int minDistance = INT16_MAX;
        for (int i = 1; i < v.size(); i++)
            minDistance = min(minDistance, v[i] - v[i - 1]);
        cout << "Minimum Distance : " << minDistance;
        cout << '\n';
        return;
    }

    printKConsecutiveSubset(a, N, K, z + 1, v);
    v.push_back(a[z]);
    printKConsecutiveSubset(a, N, K - 1, z + 1, v);
}

bool isFeasible(int mid, int K, int a[], int N)
{
    int counter = 1, t = a[0];
    for (int i = 0; i < N; i++)
    {
        if (mid <= a[i] - t)
            counter++, t = a[i];
        if (counter == K)
            return true;
    }
    return false;
}

/**
 * 
 * Intution :
 * 
 *      Checking diffrent maximum minimum distances using binary search , then checking increasing
 *      till the maximum is found 
 * 
 * Algorithm :
 * 
 *      1. Sort the array
 *      2. Start looking for minimum maximum distance using binary search
 *      3. Initialy starting the diffrence with (0+a[N-1])/2
 *      4. If the diffrence is feasible look for larger number
 *      5. If the diffrence isn't  feasible look for lower number
 *      6. The last feasible diffrence would be maximum minimum diffrence 
 *      
*/

int MaximumMinimumDistanceOfKElements(int a[], int N, int K)
{
    sort(a, a + N);
    if (K == 1)
        return 0;
    if (K == 2)
        return a[N - 1] - a[0];
    int l = 0, r = a[N - 1], mid, ans;
    while (l < r)
    {
        mid = (r + l) / 2;
        if (isFeasible(mid, K, a, N))
            ans = mid, l = mid + 1; // checking for greater values
        else
            r = mid - 1; // checking for lesser values
    }
    return ans;
}

int main()
{
    int N, K;
    cin >> N >> K;
    int a[N];
    for (int &x : a)
        cin >> x;
    cout << MaximumMinimumDistanceOfKElements(a, N, K) << '\n';
    // printKConsecutiveSubset(a, N, K);
}

/*
Input #1 :

5 3
18 34 56 12 89

Output :

33

[pair -> 12 56 89]

Input #2 :

10 4
29 75 45 39 18 97 102 49 91 12

26

[pair -> 12 45 75 102]

*/