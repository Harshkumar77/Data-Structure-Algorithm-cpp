#include <bits/stdc++.h>
using namespace std;

int postfix_evaluation(string s)
{
    // works only for single digit numbers with no spaces
        int v1, v2;
        stack<int> st;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] <= '9' and s[i] >= '0')
                st.push(s[i] - '0');
            else
            {
                v1 = st.top();
                st.pop();
                v2 = st.top();
                st.pop();
                switch (s[i])
                {
                case '^':
                    st.push(pow(v1, v2));
                    break;
                case '+':
                    st.push(v1 + v2);
                    break;
                case '-':
                    st.push(v1 - v2);
                    break;
                case '*':
                    st.push(v1 * v2);
                    break;
                case '/':
                    st.push(v1 / v2);
                    break;
                }
        }
    }
    return st.top();
}

int main()
{
    string s;
    cin >> s;
    cout<< postfix_evaluation(s);
}