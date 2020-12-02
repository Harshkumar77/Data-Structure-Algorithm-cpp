#include<iostream>
using namespace std;

void removeDup(string s , int idx , int uidx )
{
    if(idx==s.length()) return;
    if(s[idx]==s[uidx])
    {
        if(idx==0) cout<<s[0];
        removeDup(s , idx+1 , uidx);
    }    
    else
    {
        cout<<s[idx];
        removeDup(s , idx+1 , idx);
    }
    
}

int main()
{
    string s;
    cin>>s;
    removeDup(s , 0 , 0);
    return 0;
}