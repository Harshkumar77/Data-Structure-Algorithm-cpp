#include <iostream>
#include <queue>
#include <vector>
//TODO:add cmts 🙏🙏
using namespace std;

int minCompTime(vector<int> v)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int x : v)
        minHeap.push(x);
    int f, s;
    while (not minHeap.empty())
    {
        f = minHeap.top();
        minHeap.pop();
        if (minHeap.empty())
            return f;
        s = minHeap.top();
        minHeap.pop();
        minHeap.push(f + s);
    }
    return -1;
}

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (auto &x : v)
        cin >> x;
    cout << minCompTime(v) << '\n';
}