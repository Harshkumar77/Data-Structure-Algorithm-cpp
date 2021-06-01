#include <iostream>
#include <set>

// inserion , deletion and accessing has time complexity O(log n)
using namespace std;
void printSet(multiset<int> s);
int main()
{
    multiset<int> s; // Empty multiset initialised
                     // All the functons are similar but unlike set it can store repeated element

    s.insert(3), s.insert(12), s.insert(3), s.insert(-2), s.insert(23), s.insert(12);
    printSet(s);

    s.erase(3); // it will remove all the 3 present in set
    printSet(s);

    s.erase(s.find(12)); // it will only remove first 12 present in multiset
    printSet(s);
}

void printSet(multiset<int> s)
{
    for (int x : s)
        cout << x << ' ';
    cout << '\n';
}