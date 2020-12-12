#include <bits/stdc++.h>
using namespace std;
class student
{
public:
    string name;
    int age;
    bool gender;

    void printInfo()
    {
        cout << name << "'s age is " << age << " his/her gender is ";
        if (gender)
            cout << "male";
        else
            cout << "female";
        cout << '\n';
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    student a[n];
    for (auto &x : a)
        cin >> x.name >> x.age >> x.gender;
    for (auto x : a)
        x.printInfo();
    return 0;
}