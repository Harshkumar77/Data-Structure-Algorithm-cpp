#include <iostream>
class node
{
public:
    int data;
    node *next = NULL;

    node(int val)
    {
        data = val;
    }
};
class queue
{
    node *front = NULL;
    node *back = NULL;

public:
    bool empty()
    {
        return (front == NULL);
    }

    void push(int x)
    {
        node *t = new node(x);
        if (this->empty())
        {
            front = t, back = t;
            return;
        }
        back->next = t;
        back = back->next;
    }

    void pop()
    {
        if (this->empty())
        {
            std::cout << "queue is empty\n";
            return;
        }
        node *del = front;
        front = front->next;
        delete del;
    }

    int peek()
    {
        if (this->empty())
        {
            std::cout << "queue is empty\n";
            return -1;
        }
        return front->data;
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