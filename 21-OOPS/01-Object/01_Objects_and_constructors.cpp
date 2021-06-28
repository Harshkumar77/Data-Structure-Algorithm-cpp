#include <iostream>

class Student // creating a class
{
public:
    // data members
    std::string name = "UNKNOWN";
    int Class = -1;

    Student() {} // default constructor
    // calling this constructor would provide
    // default value to the object

    Student(std::string name, int Class)
    {
        // A constructor with parameter
        this->name = name;
        this->Class = Class;
    }
};

int main()
{
    Student hades("HADES", 7);
    // created a object of student using paramaterised constructor
    std::cout << hades.Class << '\n'
              << hades.name << '\n';
    Student tevor;
    // using default constructor
    std::cout << tevor.name << '\n'
              << tevor.Class << '\n';

    Student nora{"NORA", 10};
    // another way of calling constructor
    std::cout << nora.name << '\n'
              << nora.Class;
    return 0;
}
