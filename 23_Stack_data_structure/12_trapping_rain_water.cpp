#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N, top, water = 0, length, height;
    cin >> N;
    int a[N];
    for (int &x : a)
        cin >> x;
    stack<int> s;
    for (int i = 0; i < N; i++)
    {
        while (not s.empty() and a[s.top()] < a[i])
        {
            top = s.top();
            s.pop();
            if (not s.empty())
            {
                length = i - s.top() - 1, height = min(a[s.top()] - a[top], a[i] - a[top]);
                water += length * height;
            }
        }
        s.push(i);
    }
    cout << water;
}