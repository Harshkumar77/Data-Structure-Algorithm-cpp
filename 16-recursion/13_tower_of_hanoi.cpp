#include <iostream>
using namespace std;

void toh(int n , char src , char dest , char help )
{
    if(n==0) return;
    toh(n-1 , src , help , dest);
    cout<<src<<" to "<<dest<<'\n';
    toh(n-1 , help , dest , src);
}

int main()
{
    toh(3,'A','B','C');
    return 0;
}