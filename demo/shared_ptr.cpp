#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class MyClass
{
public:
    MyClass() { cout << "MyClass()" << endl; }
    ~MyClass() { cout << "~MyClass()" << endl; }
};

int main()
{
    shared_ptr<MyClass> p1(new MyClass());
    {
        shared_ptr<MyClass> p2 = p1;
        cout << "p1.use_count() = " << p1.use_count() << endl;
        cout << "p2.use_count() = " << p2.use_count() << endl;
    }
    cout << "p1.use_count() = " << p1.use_count() << endl;
    return 0;
}
