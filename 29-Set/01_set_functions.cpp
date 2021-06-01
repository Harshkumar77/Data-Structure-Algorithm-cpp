#include <iostream>
#include <set>
// inserion , deletion and accessing has time complexity O(log n)
using namespace std;
void printSet(set<int> s);
int main()
{
    set<int> s; // Empty set initialised
    s.insert(43), s.insert(21), s.insert(54), s.insert(12);
    // Inserting elements in set

    /*              Method of traversing in sets        */
    cout << "Traversing set :" << '\n';
    for (int x : s)
        cout << x << ' ';

    cout << '\n';

    cout << "Traversing set :" << '\n';
    for (set<int>::iterator i = s.begin(); i != s.end(); i++)
        cout << *i << ' ';

    cout << '\n';

    cout << "Traversing set in reverse order :" << '\n';
    for (set<int>::reverse_iterator i = s.rbegin(); i != s.rend(); i++) // reverse order
        cout << *i << ' ';

    cout << '\n';

    /*                      Set functions                      */

    s.insert(23), s.insert(98), s.insert(32), s.insert(43), s.insert(43); // if we try to add already added element
    // for inserting in set                                               // it wont be added
    printSet(s);

    s.erase(12), s.erase(43);
    // for removing elements for set
    printSet(s);

    cout << *s.upper_bound(54) << '\n';              // upper bound returns the immediate greater element of key
    cout << (s.end() == s.upper_bound(100)) << '\n'; // in case it exceeds the largest element it returns s.end()
    cout << *s.lower_bound(32) << '\n';              // lower bound return the element
    cout << *s.lower_bound(40) << '\n';              // in case element is not found it return immediate greater
                                                     // element of the key
}

void printSet(set<int> s)
{
    for (int x : s)
        cout << x << ' ';
    cout << '\n';
}

/*

Recived Output :

Traversing set :
12 21 43 54 
Traversing set :
12 21 43 54 
Traversing set in reverse order :
54 43 21 12 
12 21 23 32 43 54 98 
21 23 32 54 98 
98
1
32
54

*/