#include <iostream>
#include <stack>
using namespace std;

bool is_balanced(string s)
{
    stack<char> bracket;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '{' or s[i] == '(' or s[i] == '[')
            bracket.push(s[i]);
        else if (s[i] == ')')
            if (!bracket.empty() and bracket.top() == '(')
                bracket.pop();
            else
                return false;
        else if (s[i] == '}')
            if (!bracket.empty() and bracket.top() == '{')
                bracket.pop();
            else
                return false;
        else if (s[i] == ']')
            if (!bracket.empty() and bracket.top() == '[')
                bracket.pop();
            else
                return false;
        else
            return false;
    if (!bracket.empty())
        return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << is_balanced(s) << '\n';
    return 0;
}