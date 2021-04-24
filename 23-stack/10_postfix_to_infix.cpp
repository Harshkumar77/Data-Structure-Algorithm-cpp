#include <iostream>
#include <stack>
using namespace std;

string postfix_to_infix(string s)
{
    string s1, s2;
    stack<string> st;
    for (int i = 0; i < s.length(); ++i)
    {
        if ((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= 'a' and s[i] <= 'z'))
        {
            string a = "";
            a.push_back(s[i]);
            st.push(a);
        }
        else
        {
            s1 = st.top();
            st.pop();
            s2 = st.top();
            st.pop();
            string a = "";
            a.push_back('(');
            a.append(s2);
            a.push_back(s[i]);
            a.append(s1);
            a.push_back(')');
            st.push(a);
        }
    }
    return st.top();
}

int main()
{
    cout<<postfix_to_infix("ABC/-AK/L-*");
}