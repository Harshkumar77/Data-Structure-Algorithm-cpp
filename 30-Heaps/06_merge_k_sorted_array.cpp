#include <iostream>
#include <queue>
using namespace std;

/**
 * Program to merge K sorted array of diffrent sizes
 * TC - O ( N log K ) // N - total number of elements in all arrays
 * SC - O ( K )
*/

/**
 * Algorithm :
 * 1. Add left most elements of arrays in a min heap
 * 2. Keep poping the smallest element from the heap while pushing
 *    the next sequencial greater element poped
 * 
*/
vector<int> merge(vector<vector<int>> &v, int K)
{
    vector<int> sorted;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
    // element // Index // vector-index
    for (int i = 0; i < K; i++)
        p.push({v[i][0], {0, i}});
    pair<int, pair<int, int>> temp;
    while (not p.empty())
    {
        temp = p.top();
        p.pop();
        sorted.push_back(temp.first);
        if (v[temp.second.second].size() > temp.second.first + 1)
            p.push({v[temp.second.second][temp.second.first + 1], {temp.second.first + 1, temp.second.second}});
    }
    return sorted;
}

int main()
{
    int K, N;
    cin >> K;
    vector<vector<int>> v(K);
    for (vector<int> &x : v)
    {
        cin >> N;
        x = vector<int>(N);
        for (int &y : x)
            cin >> y;
    }
    for (int x : merge(v, K))
        cout << x << ' ';
    return 0;
}