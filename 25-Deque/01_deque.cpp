#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> d;
    d.push_back(24);
    d.push_back(43);
    d.push_front(34);
    d.push_back(45);

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << ' ';
    }
    cout << '\n';

    d.pop_back();

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << ' ';
    }
    cout << '\n';
    d.pop_front();

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << ' ';
    }
    cout << '\n';
}