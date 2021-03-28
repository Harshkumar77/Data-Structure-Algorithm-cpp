#include <iostream>
#include <queue>

using namespace std;

class stack
{
    int N = 0;
    queue<int> q1, q2;

public: 
    bool empty()
    {
        return q1.empty();
    }
    void push(int x)
    {
        q1.push(x);
    }
    void pop()
    {
        if (empty())
        {
            cout << "EMPTY";
            return;
        }
        while (!q1.empty())
        {
            int x = q1.front();
            q1.pop();
            if (!this->empty())
                q2.push(x);
        }
        queue<int> t = q2;
        q2 = q1;
        q1 = t;
    }
    int top()
    {
        if (this->empty())
        {
            cout << "Empty";
            return -1;
        }
        else
        {
            int x;
            while (!q1.empty())
            {
                x = q1.front();
                q1.pop();
                q2.push(x);
            }
            queue<int> t = q2;
            q2 = q1;
            q1 = t;
            return x;
        }
    }
};

int main()
{
    stack y;
    y.push(1);
    y.push(2);
    y.push(3);
    y.push(3);
    y.push(4);
    y.push(50);
    while (!y.empty())
        cout << y.top() << '\n', y.pop();
}