#include <iostream>
using namespace std;

void replacePi(string s, int idx)
{
    if (idx == s.length())
    {
        return;
    }
    if (s[idx] == 'p' and s[idx + 1] == 'i')
    {
        cout << 3.14;
        replacePi(s, idx + 2);
    }
    else
    {
        cout << s[idx];
        replacePi(s, idx + 1);
    }
}

int main()
{
    string s;
    cin >> s;
    replacePi(s, 0);
    return 0;
}
