#include <iostream>
using namespace std;

class queue
{
    int *arr;
    int front = -1;
    int back = -1;

public:
    queue()
    {
        arr = new int[1000];
    }
    void push(int a)
    {
        if (back == 999)
        {
            cout << "queue overflow\n";
            return;
        }
        if (front == -1 and back == -1)
            front = 0;
        arr[++back] = a;
    }
    void pop()
    {
        if (front == -1)
            cout << "Nothing to pop\n";
        else
            ++front;
    }
    int peek()
    {
        if (front == -1)
        {
            cout << "Nothing to pop\n";
            return -1;
        }
        else
            return arr[front];
    }
    bool empty()
    {
        if (back < front)
            return true;
        return false;
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
        cout << q.peek() , q.pop();
    }
    
}