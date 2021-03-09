#include <iostream>
#include <stack>
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

string infix_to_postfix(string s)
{
    string postfix = "";
    stack<char> st;
    for (int i = 0; i < s.length(); ++i)
    {
        if ((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= 'a' and s[i] <= 'z'))
            postfix.push_back(s[i]);
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() and prec(s[i]) < prec(st.top()))
            {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
        postfix.push_back(st.top()), st.pop();
    return postfix;
}

int main()
{
    string exp;
    cin >> exp;
    cout << infix_to_postfix(exp);
}