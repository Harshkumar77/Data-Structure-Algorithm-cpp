#include<iostream>
using namespace std;

int freindPairing(int n)
{
    if (n ==0 or n==1 or n==2)
    {
        return n;
    }
    return freindPairing(n-1) + (n-1)*freindPairing(n-2);
}

int main()
{
    int n;
    cin>>n;cout<<freindPairing(n);
}