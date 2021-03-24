#include <iostream>
#include <stack>

class queue
{
    std::stack<int> s1;
    std::stack<int> s2;

public:
    bool empty()
    {
        return s1.empty();
    }

    void push(int x)
    {
        s1.push(x);
    }

    void pop()
    {
        if (this->empty())
        {
            std::cout << "empty";
            return;
        }
        while (!s1.empty())
            s2.push(s1.top()), s1.pop();
        s2.pop();
        while (!s2.empty())
            s1.push(s2.top()), s2.pop();
    }

    int peek()
    {
        if (this->empty())
        {
            std::cout << "empty";
            return -1;
        }
        while (!s1.empty())
            s2.push(s1.top()), s1.pop();
        int f = s2.top();
        while (!s2.empty())
            s1.push(s2.top()), s2.pop();
        return f;
    }
};

int main()
{
    queue q;
    q.push(2);
    q.push(6);
    q.push(5);
    q.push(4);
    q.push(3);
    while (!q.empty())
    {
        std::cout << q.peek(), q.pop();
    }
}