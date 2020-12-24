#include <bits/stdc++.h>
using namespace std;

//function overloading

class OBJ{
    public :
        void A()
        {
            cout<<"function with No arg\n";
        }
    public :
        void A(int a)
        {
            cout<<"function with Integer arg\n";
        }
    public :
        void A(double a)
        {
            cout<<"function with Double arg\n";
        }
} ;

int main()
{
    OBJ o;
    o.A();
    o.A(21);
    o.A(99.32);
    return 0;
}