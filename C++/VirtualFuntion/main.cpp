#include <iostream>

class Base
{
public:
virtual std::string getName() const
{
return "Base";
}
};

class Derived : public Base
{
public:
std::string getName() const
{
return "Derived";
}
};

int main()
{
Base bs1, * pbs1;
Derived dv1;
pbs1 = &dv1;

std::cout << bs1.getName() << std::endl;
std::cout << dv1.getName() << std::endl;
std::cout << pbs1->getName() << std::endl;

return 0;
}
