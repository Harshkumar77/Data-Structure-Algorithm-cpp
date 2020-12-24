#include <bits/stdc++.h>
using namespace std;

//operator overloading

class complexNumber
{
public:
    int real;

public:
    int img;
    complexNumber(int a, int b)
    {
        real = a;
        img = b;
    }

public:
    void display()
    {
        cout << real << " + i" << img;
    }
    complexNumber operator + (complexNumber	&c)
    {
        complexNumber ans(c.real+real , c.img + img);
        return ans;
    }
};

int main()
{
    complexNumber c(87, 45);
    complexNumber d(32, 909);
    complexNumber A = c + d;
    cout << "sum of ";
    c.display();
    cout << " and ";
    d.display();
    cout << ' ' << "is ";
    A.display();
    return 0;
}