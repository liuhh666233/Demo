#include <memory>
#include <iostream>

using namespace std;

class MyClass
{
public:
    void DoSomething()
    {
        std::cout << "DoSomething()" << std::endl;
    }
};

int main()
{
    weak_ptr<MyClass> weakPtr;
    {
        shared_ptr<MyClass> sharedPtr(new MyClass());
        weakPtr = sharedPtr;
        sharedPtr->DoSomething();
    }
    if (auto sharedPtr = weakPtr.lock())
    {
        sharedPtr->DoSomething();
    }
    else
    {
        std::cout << "weakPtr is expired!" << std::endl;
    }
}