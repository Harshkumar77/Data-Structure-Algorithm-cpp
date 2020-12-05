#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> p, pair<int, int> p2)
{
    return p.first < p2.first;
}

int main()
{
    int arr[] = {12, 43, 17, 2, 21};
    vector<pair<int, int>> v;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        v.push_back(make_pair(arr[i], i));
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i].second]=i;
    }
    for (auto &i : arr)
    {
        cout<<i<<" ";
    }
    
}