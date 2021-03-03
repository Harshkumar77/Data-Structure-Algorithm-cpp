int prefix_evaluation(string s)
{
    // works only for single digit numbers with no spaces
    int v1, v2;
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; --i)
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
