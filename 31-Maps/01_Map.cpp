#include <iostream>
#include <map>
/**
 * Map links a key with its value
 * The benifit is value can be accessed in log N time complexity
 * 
 * All operations are in log N TC
 * 
 * The map is sorted in manner of key 
 * 
 * It is implemented in STL using red black tree
*/
using namespace std;

int main()
{
    map<string, int> m = {{"Light", 0}, {"Pro", 22}};

    m.insert({"Harsh", 7}); // "Harsh" is key and 7 is value
    m.insert({"Quote", 10});
    m.insert({"Gwen", 12});
    m["White"] = 8;

    cout << m.erase("Like") << '\n'  // return false as it is not present in map
         << m.erase("Gwen") << '\n'; // returned true as well as erased

    cout << '\n';

    // All the operators are similar as set

    for (pair<string, int> p : m)
        cout << p.first << ' ' << p.second << '\n';
    // it is ordered , in alphabatical manner

    cout << '\n';

    return 0;
}