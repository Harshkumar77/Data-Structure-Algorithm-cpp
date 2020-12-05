#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //vector basics

    // initialising vector

    vector<int> v;

    //adding element in vector

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    //iterating vector

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << '\n';

    for (auto x : v)
        cout << x << " ";
    cout << '\n';

    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); it++)
        cout << *it << ' ';
    cout << '\n';

    vector<int> v2(2, 50); // created vector of size 3 and every element is 50
    swap(v, v2);

    for (auto x : v)
        cout << x << " ";
    cout << '\n';
    for (auto x : v2)
        cout << x << " ";
    cout << '\n';

    //removing element of vector

    v2.pop_back();
    v2.push_back(34);
    cout << v2[2];

    return 0;
}