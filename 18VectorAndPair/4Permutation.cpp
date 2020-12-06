#include<iostream>
#include<vector>
using namespace std;

void permute (vector<int> &num , vector<vector<int>> &big , int idx)
{
    if (idx==num.size())
    {
        big.push_back(num);
        return;
    }
    for (int i = idx; i < num.size(); i++)
    {
        swap(num[i] , num[idx]);
        permute(num,big,idx+1);
        swap(num[i] , num[idx]);
    }   
}

int main()
{
    int n ; 
    cin>>n;
    vector<int> num(n);
    for (auto &i : num)
    {
        cin>>i;
    }
    vector<vector<int>> big;
    permute(num,big,0);
    for (auto &i : big)
    {
        for (auto &ii : i)
        {
            cout<<ii<<" ";
        }
        cout<<'\n';
    }    
}