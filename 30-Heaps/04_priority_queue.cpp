#include <bits/stdc++.h>
using namespace std;

int main()
{
    // priority queue is max heap present in stl
    priority_queue<int, vector<int>> mxHeap;
    mxHeap.push(5), mxHeap.push(6), mxHeap.push(1), mxHeap.push(9), mxHeap.push(10); // TC - O(log n)

    cout << mxHeap.top() << '\n'; // TC - O(1)
    mxHeap.pop();                 // TC - O(log n)
    cout << mxHeap.top() << '\n';

    // to use it as min heap we have to tweak it

    priority_queue<int, vector<int>, greater<int>> mnHeap;
    mnHeap.push(-9), mnHeap.push(1), mnHeap.push(3); // TC - O(log n)

    cout << mnHeap.top() << '\n'; // TC - O(1)
    mnHeap.pop();                 // TC - O(log n)
    cout << mnHeap.top() << '\n';
}