#include <iostream>
using namespace std;

void reverseString(string s, int length)
{
    if (length == 0)
        return;
    cout << s[length - 1];
    reverseString(s, length - 1);
}

int main()
{
    string s;
    cin >> s;
    reverseString(s, s.length());
}