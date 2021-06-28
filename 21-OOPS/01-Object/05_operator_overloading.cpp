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

    std::string Wing()
    {
        if (Class < 1 or Class > 12)
        {
            std::cout << "Invalid Class of " << name << '\n';
            return "";
        }
        std::string Wing[] = {"Junior", "Middle", "Senior"};
        return Wing[(Class - 1) / 4];
    }

    // here this checks seniority comparing to 2nd
    bool operator>(Student &s)
    {
        // > is overloaded to work with Student Class
        return Class > s.Class;
    }
};

int main()
{
    Student hades("HADES", 7);

    std::cout << hades.Class << '\n'
              << hades.name << '\n'
              << hades.Wing() << '\n';

    Student nora{"NORA", 12};

    std::cout << nora.name << '\n'
              << nora.Class << '\n'
              << nora.Wing() << '\n';

    std::cout << "Is nora senior than hades ?"
              << "\n"
              << (nora > hades ? "True" : "False") << '\n';
    return 0;
}
