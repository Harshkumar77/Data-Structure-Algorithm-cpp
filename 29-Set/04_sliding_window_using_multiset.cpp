/***
 * Program to find the maximum number in a slide of size K while traversing an array
 * Time Complexity : O(N log N)
 * Space Complexity : O(K)
 * 
 * More optimal solution of time complexity O(N) is mentioned in deque
*/

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int a[N];
    for (int &x : a)
        cin >> x;
    multiset<int> window;
    for (int i = 0; i < N; i++)
    {
        window.insert(a[i]);
        if (i >= K - 1)
        {
            cout << *window.rbegin() << ' ';         // rbegin will the greatest element in the array
            window.erase(window.find(a[i - K + 1])); // sending iterator so that it wont erase whole
                                                     // occurance of that element
        }
    }
}

/*

Input :

6 2
6 3 5 6 1 2

Output :
6 5 6 6 2

*/
