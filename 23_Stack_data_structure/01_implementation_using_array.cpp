#include <iostream>
using namespace std;

class stack
{
    int *arr;
    int tp = -1;

public:
    stack()
    {
        arr = new int[1000];
    }
    bool empty()
    {
        return tp == -1;
    }
    void push(int x)
    {
        arr[++tp] = x;
    }
    void pop()
    {
        if (tp != -1)
            --tp;
    }
    int top()
    {
        if (tp != -1)
            return arr[tp];
        return -1;
    }
};

int main()
{
    stack y;
    y.push(1);
    y.push(2);
    y.push(3);
    y.push(4);
    y.push(50);
    while (!y.empty())
        cout << y.top() << '\n', y.pop();
    return 0;
}