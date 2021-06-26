#include <bits/stdc++.h>
using namespace std;

/**
 * Calculate median of running stream of elements
 * 
 * TC - O ( N log N )
 * SC - O ( N )
*/

/**
 * Intution : 
 *      For calculating median we need to have middle elements in sorted 
 *      so we have to partition the array into two halves
 * 
 * Approach :
 *  1. Partion the incoming stream into two parts
 *  2. The left sorted half is stored into max heap and right sorted part
 *      in min heap
 *  3. According to situation calucate median
*/

priority_queue<int, vector<int>> mx;
priority_queue<int, vector<int>, greater<int>> mn;

void insert(int x)
{
    if (mx.size() == mn.size())
        if (not mx.empty() and x > mx.top())
            mn.push(x);
        else
            mx.push(x);
    else if (mx.size() > mn.size())
        if (mx.top() <= x)
            mn.push(x);
        else
            mn.push(mx.top()), mx.pop(), mx.push(x);
    else if (mn.top() >= x)
        mx.push(x);
    else
        mx.push(mn.top()), mn.pop(), mn.push(x);
}

float median(int x)
{
    insert(x);
    if (mx.size() == mn.size())
        return (mx.top() + mn.top()) / 2.0;
    if (mn.size() > mx.size())
        return mn.top();
    return mx.top();
}

int main()
{
    int N, X;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> X, cout << median(X) << ' ';
}
