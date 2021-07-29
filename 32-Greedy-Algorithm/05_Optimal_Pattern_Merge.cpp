#include <iostream>
#include <queue>
#include <vector>

/**
 * Program to find the optimal time to merge tasks
 * Condition :
 *  when we merge 2 tasks it creates a new task with time sum of previous 2 tasks
 * we have to merge all the tasks into 1 single task in mist optimal manner
 * */

using namespace std;

/**
 * Intution :
 * We would merge tasks with minimum times first
 * because if a larger task is merged first it will keep on increasing the task of upcoming task
 * 
 * Algorithm :
 *      1. Adding all the tasks time in a min heap
 *      2. Merge the topmost 2 tasks and add the sum again to minheap
 *      3. The last element in minheap would be the optimal time
 */
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
