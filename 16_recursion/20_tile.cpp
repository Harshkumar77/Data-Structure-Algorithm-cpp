#include <iostream>
using namespace std;

int tile(int n )
{
    if(n==1 or n==0) return n;
    return tile(n-1) + tile(n-2);   
}
int main()
{
    int n;
    cin>>n;
    cout<<tile(n);
}