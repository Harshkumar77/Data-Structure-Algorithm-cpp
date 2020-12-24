#include <bits/stdc++.h>
using namespace std;

class OBJ{
    public:
        void F1()
        {
            cout<<"public function\n";
        }
    private	:
        void F2()
        {
            cout<<"private function\n";
        }
    protected :
        void F3()
        {
            cout<<"protected function\n";
        }
};

int main()
{
    OBJ o ;
    o.F1();
    o.F2();// this will give error that F2 is dectared privately
    o.F3();// this will give error that F3 is dectared protectely
    return 0;    
}