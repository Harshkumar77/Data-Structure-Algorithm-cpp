#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, K, low, high;
    cin >> N >> K;
    int a[N];
    for (int &x : a)
        cin >> x;
    sort(a, a + N);
    for (int i = 0; i < N - 2; i++)
    {
        low = i + 1, high = N - 1;
        while (low < high)
        {
            if (a[i] + a[low] + a[high] == K)
            {
                cout << "True";
                return 0;
            }
            else if (a[i] + a[low] + a[high] < K)
                ++low;
            else
                --high;
        }
    }
    cout << "False";
}