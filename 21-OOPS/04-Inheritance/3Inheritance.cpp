#include <bits/stdc++.h>
using namespace std;

class OBJ
{
    public : 
        void f1()
        {
            cout<<"I am a orignal function of class OBJ\n";
        }
};
class OBJ2:public OBJ
{
    public :    
        void f2()
        {
            cout<<"I am a function of OBJ2\n";
        }
};

int main()
{
    OBJ2 o;
    o.f1();
    o.f2();
    return 0;
}