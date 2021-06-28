#include <iostream>

class Student
{
public:
    std::string name = "UNKNOWN";
    int Class = -1;

    Student(std::string name, int Class)
    {
        this->name = name;
        this->Class = Class;
    }

    std::string Wing() // its a method
    {
        // method is just a function
        // can be called only for this object
        if (Class < 1 or Class > 12)
        {
            std::cout << "Invalid Class of " << name << '\n';
            return "";
        }
        std::string Wing[] = {"Junior", "Middle", "Senior"};
        return Wing[(Class - 1) / 4];
    }
};

int main()
{
    Student hades("HADES", 1);

    std::cout << hades.Class << '\n'
              << hades.name << '\n'
              << hades.Wing() << '\n'; // calling method

    Student nora{"NORA", 12};

    std::cout << nora.name << '\n'
              << nora.Class << '\n'
              << nora.Wing() << '\n';
    return 0;
}
