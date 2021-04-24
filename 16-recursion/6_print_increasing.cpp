#include <iostream>
using namespace std;

void printI(int n)
{
    if(n==0) 
    {
        cout<<n<<'\n';
        return;
    }
    printI(n-1);
    cout<<n<<'\n';
    
}

int main()
{
    int n;
    cin>>n;
    printI(n);
}