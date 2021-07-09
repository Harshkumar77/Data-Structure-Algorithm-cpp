#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * Unordered Map links a key with its value
 * The benifit is value can be accessed in constant time complexity [ AVERAGE ]
 * 
 * All operations are in constant TC
 * *EXCEPT* erasing element ( For erasing it takes O ( N ) TC )
*/

int main()
{
    unordered_map<string, int> um;
    um.insert({"Harsh", 7});
    um.insert({"Quote", 10});
    um.insert({"Gwen", 12});
    um["White"] = 8;

    cout << um.erase("Like") << '\n'  // return false as it is not present in map
         << um.erase("Gwen") << '\n'; // returned true as well as erased

    cout << '\n';

    // All the operators are similar as set

    for (pair<string, int> p : um)
        cout << p.first << ' ' << p.second << '\n';

    cout << '\n';

    return 0;
}