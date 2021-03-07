#include <iostream>
#include <stack>
using namespace std;

int prec(char a)
{
    if (a == '^')
        return 4;
    if (a == '/' or a == '*')
        return 3;
    if (a == '+' or a == '-')
        return 2;
    return -1;
}

string infix_to_postfix(string s)
{

}

int main()
{
}