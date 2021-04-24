#include <bits/stdc++.h>
using namespace std;
class student
{
public:
    string mName;
    int mAge;
    bool mGender;

    student() {} // default constructor

    student(string name, int age, bool gender)
    {
        mName = name;
        mAge = age;
        mGender = gender;
    } // parameterised constructor

    student(student &q)
    {
        mName = q.mName;
        mAge = q.mAge;
        mGender = q.mGender;
    } // deep copy constructor

    void printInfo()
    {
        cout << mName << "'s age is " << mAge << " his/her gender is ";
        if (mGender)
            cout << "male";
        else
            cout << "female";
        cout << '\n';
    }

    ~student() { cout << "Destruction done\n"; } // Destructor

    bool operator==(student &a)
    {
        if (a.mAge == mAge and a.mGender == mGender and a.mName == mName)
            return true;
        return false;
    } // Operator overloading
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string name;
    int age;
    bool gender;
    cin >> name >> age >> gender;
    student A(name, age, gender);
    student b{"Tom", 12, true};
    A.printInfo();
    b.printInfo();

    if (A == b)
        cout << "Same\n";
    else
        cout << "Different\n";

    return 0;
}