#include "my_class.h"
#include <iostream>

class MyClass_Impl
{
public:
    void DoSomething()
    {
        std::cout << "Doing something" << std::endl;
    }
};

MyClass::MyClass()
    : m_pImpl(new MyClass_Impl)
{
}
MyClass::~MyClass()
{
    delete m_pImpl;
}
void MyClass::DoSomething()
{
    m_pImpl->DoSomething();
}

int main()
{
    MyClass myClass;
    myClass.DoSomething();
    return 0;
}