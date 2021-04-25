#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    string s;
    cin >> s;
    for (char c : s)
        switch (c)
        {
        case 'A' ... 'Z':
        case 'a' ... 'z':
        case '(':
            break;
        default:
            st.push(c);
        }
    while (not st.empty())
    {
        if (st.top() == ')')
        {
            st.pop();
            if (st.top() == ')')
            {
                cout << "has redundant parenthesis";
                return 0;
            }
        }
        else
            st.pop();
    }
    cout << "no redundant parenthesis";
}