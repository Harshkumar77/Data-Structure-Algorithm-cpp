#include <iostream>
#include <stack>

using namespace std;

void reverseS(string &s)
{
    stack<string> st;
    string pu = "";
    for (int i = 0; i < s.length(); ++i)
    {
        if(s[i]==' ')
            st.push(pu) , pu = "";
        else    
            pu.push_back(s[i]);
    }
    st.push(pu);
    s="";
    while (!st.empty())
    {
        s.append(st.top()+" ");
        st.pop();
    }
    
}

int main()
{
    string s;
    getline(cin, s);
    reverseS(s);
    cout << s;
}