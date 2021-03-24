#include <iostream>
#include <stack>

class queue
{
    std::stack<int> s1;

    int stackBottom(std::stack<int> &s, int prev = -1, bool remove = false)
    {
        if (s.empty())
        {
            std::cout << "Empty stack";
            return prev;
        }
        int x = s.top();
        s.pop();
        if (remove and s.empty())
            return x;
        else if (s.empty())
        {
            s.push(x);
            return x;
        }
        int y = stackBottom(s, x, remove);
        s.push(x);
        return y;
    }

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
        stackBottom(s1, -1, true);
    }

    int peek()
    {
        if (this->empty())
        {
            std::cout << "empty";
            return -1;
        }
        return stackBottom(s1, -1, false);
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
        std::cout << q.peek()<<'\n' , q.pop();
}