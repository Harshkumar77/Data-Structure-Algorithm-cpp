#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
// TODO:Add cmts
vector<int> KfrequentElements(vector<int> v, int N, int K)
{
    unordered_map<int, int> u;
    for (int x : v)
        u[x]++;
    vector<pair<int, int>> srt;
    for (auto x : u)
        srt.push_back({x.second, x.first});
    sort(srt.rbegin(), srt.rend());
    vector<int> top;
    for (int i = 0; i < K; i++)
        top.push_back(srt[i].second);
    return top;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int &x : v)
        cin >> x;
    for (int x : KfrequentElements(v, N, K))
        cout << x << ' ';
}