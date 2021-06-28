#include <iostream>

class Student
{
public:
    std::string name = "UNKNOWN";
    int Class = -1;
    bool isMale = true;

    Student(std::string name, int Class)
    {
        this->name = name;
        this->Class = Class;
    }

    Student(std::string name, int Class, bool isMale) : Student(name, Class)
    {
        this->isMale = isMale;
    }
    // this is a delegating constructor

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

    bool operator>(Student &s)
    {
        return Class > s.Class;
    }
};

int main()
{
    Student hades("HADES", 7);

    std::cout << hades.Class << '\n'
              << hades.name << '\n'
              << hades.Wing() << '\n';

    Student nora{"NORA", 12, false};

    std::cout << nora.name << '\n'
              << nora.Class << '\n'
              << nora.Wing() << '\n';

    std::cout << "Is nora senior than hades ?"
              << "\n"
              << (nora > hades ? "True" : "False") << '\n';
    return 0;
}