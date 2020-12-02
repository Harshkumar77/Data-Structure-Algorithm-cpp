#include <iostream>
using namespace std;

void printD(int n)
{
    if(n==0) 
    {
        cout<<n<<'\n';
        return;
    }
    cout<<n<<'\n';
    printD(n-1);
    
}

int main()
{
    int n;
    cin>>n;
    printD(n);
}