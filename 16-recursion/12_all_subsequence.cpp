#include <iostream>
using namespace std;

void subs(string s , string ans)
{
    if(s.length()==0) 
    {
        cout<<ans<<'\n';
        return;
    }
        subs(s.substr(1) , ans+s[0]);
        subs(s.substr(1),ans);
    
}

int main()
{
    string s;
    cin >> s;
    subs(s ,"");
}