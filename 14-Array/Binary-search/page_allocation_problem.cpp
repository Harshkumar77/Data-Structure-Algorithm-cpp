#include <bits/stdc++.h>
using namespace std;

/**
 * Given number of pages in n different books and m students. 
 * The books are arranged in ascending order of number of pages.
 * Every student is assigned to read some consecutive books. 
 * The task is to assign books in such a way that the maximum 
 * number of pages assigned to a student is minimum. 
 * 
 * Time Complexity : O ( N log n )
 *      N = Size_of_Array , n = Sum_of_array 
 * 
 * Space Complexity : O ( 1 )
 * 
*/

bool AllocationPossible(int a[], int N, int S, int mid)
{
    int sum_till_now = 0, s = 1;
    for (int i = 0; i < N; i++)
    {
        if (a[i] > mid)
            return false;
        else if ((a[i] + sum_till_now) > mid)
        {
            sum_till_now = a[i], s++;
            if (S < s)
                return false;
        }
        else
            sum_till_now += a[i];
    }
    return true;
}
/**
 * Intution : 
 * 
 *      Checking diffrent values maximum book allotment using binary search and 
 *      reducing values till the minimum of them is found
 * 
*/
int MinimumMaximumPagesAllocated(int a[], int N, int S)
{
    int l = 0, r = accumulate(a, a + N, 0), mid, ans;
    // accumulate used for finding sum of array present in stdlib
    while (l < r)
    {
        mid = (l + r) / 2;
        if (AllocationPossible(a, N, S, mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    return ans;
}
int main()
{
    int N, S;
    cin >> N >> S;
    int a[N];
    for (int &x : a)
        cin >> x;
    cout << MinimumMaximumPagesAllocated(a, N, S);
}
/*  

Input : 

4 2
12 34 67 90

Output :

113

*/