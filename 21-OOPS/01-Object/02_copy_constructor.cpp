#include <iostream>

class fruit
{
public:
    std::string name;
    std::string color;

    fruit(std::string name, std::string color)
    {
        this->name = name;
        this->color = color;
    }
    //copy constructor
    fruit(fruit &f)
    {
        this->name = f.name;
        this->name = color;
    }
};

int main()
{
    fruit apple("apple", "red");
    fruit copyApple(apple);
    copyApple.color = "green";
    std::cout << apple.color << ' '
              << copyApple.color;
}