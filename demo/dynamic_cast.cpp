#include <iostream>

class Base
{
    virtual void dummy(){};
};

class Derived : public Base
{
public:
    void dummy()
    {
        std::cout << "Derived dummy" << std::endl;
    };
};

int main()
{
    Base *b = new Derived;
    Derived *d = dynamic_cast<Derived *>(b);
    if (d != nullptr)
    {
        d->dummy();
    }
    return 0;
}