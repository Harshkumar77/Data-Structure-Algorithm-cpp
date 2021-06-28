#include <iostream>

class Student // creating a class
{
public:
    // data members
    std::string name = "UNKNOWN";
    int *Class = new int(-1);

    Student(std::string name, int Class)
    {
        this->name = name;
        *this->Class = Class;
    }

    ~Student()
    {
        // this is a destructor
        // it is called when program is ending
        // should free every dynammically allocated memory here
        delete Class;
        std::cout << "Destroying " << name << " object\n";
    }
};

int main()
{
    Student hades("HADES", 7);

    std::cout << *hades.Class << '\n'
              << hades.name << '\n';

    Student nora{"NORA", 10};

    std::cout << nora.name << '\n'
              << *nora.Class << '\n';
    return 0;
}
