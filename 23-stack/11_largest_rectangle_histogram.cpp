#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void p(stack<int> st)
{
    if (st.empty())
        return;

    int t = st.top();
    st.pop();
    if (st.empty())
    {
        cout << t << ' ';
        return;
    }
    p(st);
    cout << t << ' ';
}

int main()
{
    int n, area = -1;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    a.push_back(0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and a[st.top()] > a[i])
        {
            int h = a[st.top()];
            st.pop();
            if (st.empty())
                area = max(area, h * i);
            else
                area = max(area, h * (i - st.top() - 1));
        }
        st.push(i);
    }
    cout << area;
}