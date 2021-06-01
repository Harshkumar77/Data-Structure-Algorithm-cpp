#include <iostream>
#include <unordered_set>
// inserion , deletion and accessing has time complexity
// O(1) [Average] and O(N) [Worst case]
using namespace std;

void printUnorderedSet(unordered_set<int> us)
{
    for (int x : us)
        cout << x << ' ';
    cout << '\n';
}
void printUnorderedSet(unordered_multiset<int> ums)
{
    for (int x : ums)
        cout << x << ' ';
    cout << '\n';
}
int main()
{
    unordered_set<int> us; // Empty unordered set initialised
    us.insert(1);          // 1
    us.insert(8);          // 8 1
    us.insert(1);          // 8 1
    us.insert(4);          // 4 8 1
    us.insert(8);          // 4 8 1
    us.insert(4);          // 4 8 1
    printUnorderedSet(us); // order is similar of stack

    unordered_multiset<int> ums; // Empty unordered set initialised
    ums.insert(1);
    ums.insert(8);
    ums.insert(1);
    ums.insert(4);
    ums.insert(8);
    ums.insert(6);
    ums.insert(8);
    ums.insert(4);
    ums.insert(6);
    ums.insert(4);
    printUnorderedSet(ums); // No order is maintained all the same elements are grouped
                            // together not even in order of insertions
}