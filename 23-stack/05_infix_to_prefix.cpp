#include <bits/stdc++.h>
using namespace std;

int prec(char a)
{
    if (a == '^')
        return 4;
    if (a == '/' or a == '*')
        return 3;
    if (a == '+' or a == '-')
        return 2;
    return -1;
}

string infix_to_prefix(string s)
{
    string prefix = "";
    stack<char> st;
    for (int i = s.length() - 1; i >= 0; --i)
    {
        if (s[i] == ')')
            st.push(s[i]);
        else if (s[i] == '(')
        {
            while (st.top() != ')')
                prefix.push_back(st.top()), st.pop();
            if (!st.empty())
                st.pop();
        }
        else if ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z'))
        {
            prefix.push_back(s[i]);
        }
        else
        {
            while (!st.empty() and prec(st.top()) < prec(s[i]))
                prefix.push_back(st.top()), st.pop();
            st.push(s[i]);
        }
    }
    while (!st.empty())
        prefix.push_back(st.top()), st.pop();
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string s;
    cin >> s;
    cout << infix_to_prefix(s);
}
