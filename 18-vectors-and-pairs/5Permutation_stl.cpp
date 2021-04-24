#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void permute (vector<int> &num , vector<vector<int>> &big , int idx)
{
    sort(num.begin() , num.end());
    do
    {
        big.push_back(num);
    } while (next_permutation(num.begin() , num.end()));
    
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