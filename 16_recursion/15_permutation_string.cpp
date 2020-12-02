#include <iostream>
using namespace std;

void stringPermutation(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << '\n';
    }

    for (int i = 0; i < s.size(); i++)
    {
        stringPermutation(s.substr(0, i) + s.substr(i + 1), ans + s[i]);
    }
}

int main()
{
    string s;
    cin >> s;
    stringPermutation(s, "");
}