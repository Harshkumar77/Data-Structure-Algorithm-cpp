#include <iostream>
using namespace std;

string keypadi[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string a, string ans = "" )
{
    if (ans.length() == 2)
    {
        cout << ans << '\n';
        return;
    }
    string code = keypadi[a[0]-'0'];
    string remKeys = a.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        keypad(remKeys , ans+code[i]);
    }
}

int main()
{
    string s;
    cin >> s;
    keypad(s);
    return 0;
}
