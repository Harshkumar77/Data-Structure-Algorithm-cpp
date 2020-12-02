#include <iostream>
using namespace std;

isSorted(int a[] , int length)
{
    if (length==1)
    {
        return true;
    }
    return a[length-1]>=a[length-2] and isSorted(a,length-1);
}

int main()
{
    int length;
    cin >> length;
    int a[length];
    for(auto &i : a)
        cin>>i;
    cout<<isSorted(a , length) ;
    return 0;
}