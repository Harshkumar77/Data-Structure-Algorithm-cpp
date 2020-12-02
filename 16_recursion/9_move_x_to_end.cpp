#include <iostream>
using namespace std;

string movex(string s)
{
    if (s.length() == 0)
        return s;
    if (s[0] == 'x')
        return movex(s.substr(1)) + s[0];
    else
        return s[0] + movex(s.substr(1));
}

int main()
{
    string s;
    cin >> s;
    cout << movex(s);
}